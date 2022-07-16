import os
import csv
from datetime import datetime
import requests
import json
import time


def get_contest_list():
    start_time = time.time()
    url = 'https://codeforces.com/api/contest.list'
    response = requests.get(url)
    end_time = time.time()
    print('Request took {0:.2f}s'.format(end_time - start_time))

    json_obj = json.loads(response.text)
    if json_obj['status'] == 'OK':
        contest_list = json_obj['result']
        print('Fetched {} {}'.format(len(contest_list),
              'contests' if len(contest_list) > 1 else 'contest'))
        return contest_list
    else:
        raise Exception(json_obj['comment'])


def get_problem_list():
    start_time = time.time()
    url = 'https://codeforces.com/api/problemset.problems'
    response = requests.get(url)
    end_time = time.time()
    print('Request took {0:.2f}s'.format(end_time - start_time))

    json_obj = json.loads(response.text)
    if json_obj['status'] == 'OK':
        problem_list = json_obj['result']['problems']
        print('Fetched {} {}'.format(len(problem_list),
              'problems' if len(problem_list) > 1 else 'problem'))
        return problem_list
    else:
        raise Exception(json_obj['comment'])



problem_list = get_problem_list()
contest_list = get_contest_list()

parent_path = 'C:\\Users\\utchchhwas\\OneDrive\\Documents\\Competitive Programming\\competitive-programming\\notion-integration'


problem_db = set()

export_file_path = 'C:\\Users\\utchchhwas\\OneDrive\\Documents\\Competitive Programming\\competitive-programming\\notion-integration\\notion_export\\notion_export.csv'

with open(export_file_path, 'r', encoding='utf-8') as csv_file:
    reader = csv.DictReader(csv_file)
    for row in reader:
        problem_db.add(row['Problem ID'])

print(f'{len(problem_db)} problems in database')


def get_contest_name(contest_id):
    for contest in contest_list:
        if contest['id'] == contest_id:
            return contest['name']
    raise Exception('No such contest with contest id = {}'.format(contest_id))


def get_problem_link(problem):
    return 'https://codeforces.com/contest/{}/problem/{}'.format(problem['contestId'], problem['index'])


def get_contest_link(problem):
    return 'https://codeforces.com/contest/{}'.format(problem['contestId'])


def get_rating(problem):
    return problem['rating'] if 'rating' in problem else 0


def getTags(problem):
    return ', '.join(problem['tags'])


def get_problem_id(problem):
    return str(problem['contestId']) + problem['index']


def get_contest_date(contest_id):
    for contest in contest_list:
        if contest['id'] == contest_id:
            return str(datetime.fromtimestamp(contest['startTimeSeconds']).date());
    raise Exception('No such contest with contest id = {}'.format(contest_id))


def get_database_format(problem):
    return {
        'platfrom': 'Codeforces',
        'problem_id': get_problem_id(problem),
        'problem_name': problem['name'],
        'rating': str(problem['rating']),
        'status': None,
        'problem_link': get_problem_link(problem),
        'contest_name': get_contest_name(problem['contestId']),
        'Contest_date': get_contest_date(problem['contestId']),
        'contest_link': get_contest_link(problem),
        'tags': getTags(problem),
        'last_edit': None
    }


new_problems = []
for problem in problem_list:
    if 'rating' in problem and get_problem_id(problem) not in problem_db:
        new_problems.append(problem)


print(f'Adding {len(new_problems)} new problems to the database')


import_path = os.path.join(parent_path, 'notion_import')
if not os.path.isdir(import_path):
    os.mkdir(import_path)

with open(os.path.join(import_path, 'import-{}.csv'.format(datetime.now().timestamp())), 'w', encoding='utf-8') as csv_file:
    header_row = [
        'Platform',
        'Problem ID',
        'Problem Name',
        'Rating',
        'Status',
        'Problem Link',
        'Contest Name',
        'Contest Date',
        'Contest Link',
        'Tags',
        'Last Edit'
    ]
    writer = csv.writer(csv_file)
    writer.writerow(header_row)
    for problem in new_problems:
        writer.writerow(get_database_format(problem).values())
