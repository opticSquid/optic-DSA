def parse_json(json_str):
    json_dict = {}
    parts = json_str.strip('{}').split(',')
    for part in parts:
        key,value = part.split(':')
        json_dict[key.strip('""')] = value.strip('""')
    return json_dict
def find_different_keys(json1_str, json2_str):
    json1 = parse_json(json1_str)
    json2 = parse_json(json2_str)
    differing_keys = []
    for key in json1:
        if key in json2 and json1[key]!=json2[key]:
            differing_keys.append(key)
    differing_keys.sort()
    return differing_keys
json1_str = '{"hello":"world","hi":"hello","you": "me"}'
json2_str = '{"hello": "india","hi":"hello","you":"they"}'
json3_str = '{"hacker":"rank","input":"output"}'
json4_str = '{"hacker": "ranked","input":"wrong"}'
result1 = find_different_keys(json1_str, json2_str)
result2 = find_different_keys(json3_str,json4_str)
print(result1) # ['hello', 'you']
print(result2) # ['hacker', 'input']
