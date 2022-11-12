import argparse

def match_pattern(text, pattern):
    positions = []
    text_length = len(text)
    pattern_length = len(pattern)
    position = 0
    for i, c in enumerate(text):

        if position < text_length - pattern_length and c == pattern[position]:
            offset = 0
        while(offset < pattern_length):
            if text[i + offset] == pattern[position + offset]:
                offset = offset + 1
            else:
                break
        if offset == pattern_length:
            positions.append(i)
        position = 0

    return positions

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Brute Force Pattern Matching')
    parser.add_argument('--case_sensitive', default = False, type=bool, help='Allow case sensitive checking')
    args = parser.parse_args()

    case_sensitive = args.case_sensitive

    with open('PM_input.txt') as file:
        lines = file.readlines()
    text = ""
    text = text.join(lines)
    pattern = input('Enter pattern for checking\n')
    print("Text Length : {}".format(len(pattern)))
    print("Text Text : {}".format(len(text)))

    if not case_sensitive:
        text = text.lower()
        pattern = pattern.lower()

    res = pattern.find("*")
    if res > 0 :
        print("Initiating Regex Search")
        parts = pattern.split("*")
        first_position = match_pattern(text, parts[0])
        second_position = match_pattern(text, parts[1])
        if len(first_position)>0 or len(second_position)>0:
            for u in first_position:
                for v in second_position:
                    if v >= u + len(parts[0]):
                        print("Matched found at {} {}".format(u,v))
        else:
            print("Pattern not found")
    else:
        print("Initiating Normal Search")
        position = match_pattern(text, pattern)
        for p in position:
            print("Matched found at {}".format(p))

