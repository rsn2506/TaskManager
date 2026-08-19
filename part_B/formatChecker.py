#!/usr/bin/env python3
"""
formatChecker.py

Lightweight input/output format checker for Assignment 1 Part B (Deadline Panic).
This does NOT check correctness of the underlying algorithm — only that the
output is shaped the way the autograder expects.

Usage:
    python3 formatChecker.py sampleInputFile.txt studentOutput.txt
"""

import sys

def usage():
    print("Usage: python3 formatChecker.py <inputfile> <outputfile>")
    sys.exit(2)

def main():
    if len(sys.argv) != 3:
        usage()

    input_path, output_path = sys.argv[1], sys.argv[2]

    with open(input_path, "r", encoding="utf-8") as f:
        lines = [ln.strip() for ln in f if ln.strip()]

    if not lines:
        print("FORMAT ERROR: empty input file")
        sys.exit(1)

    try:
        n = int(lines[0])
    except ValueError:
        print("FORMAT ERROR: first line must be integer N")
        sys.exit(1)

    if len(lines) != n + 1:
        print(f"FORMAT ERROR: expected {n} operation lines, found {len(lines) - 1}")
        sys.exit(1)

    expected_output_ops = []  # list of (op_num, action_id)
    for i in range(1, n + 1):
        parts = lines[i].split()
        try:
            action = int(parts[0])
        except (IndexError, ValueError):
            print(f"FORMAT ERROR: malformed operation on input line {i + 1}")
            sys.exit(1)

        # Operation number is implicitly the 1-based line index
        op_num = i 

        if action == 1:
            if len(parts) != 3:
                print(f"FORMAT ERROR: RECEIVE expects: 1 taskId priority (line {i + 1})")
                sys.exit(1)
        elif action in (2, 5, 6):
            if len(parts) != 1:
                print(f"FORMAT ERROR: action {action} expects no extra args (line {i + 1})")
                sys.exit(1)
            expected_output_ops.append((op_num, action))
        elif action == 3:
            if len(parts) != 2:
                print(f"FORMAT ERROR: action {action} expects taskId (line {i + 1})")
                sys.exit(1)
            expected_output_ops.append((op_num, action))
        elif action == 4:
            if len(parts) not in (1, 2):
                print(f"FORMAT ERROR: action 4 expects optional taskId (line {i + 1})")
                sys.exit(1)
            expected_output_ops.append((op_num, action))
        else:
            print(f"FORMAT ERROR: unknown action id {action} on line {i + 1}")
            sys.exit(1)

    with open(output_path, "r", encoding="utf-8") as f:
        out_lines = [ln.rstrip("\n") for ln in f if ln.strip()]

    if len(out_lines) != len(expected_output_ops):
        print(
            f"FORMAT ERROR: expected {len(expected_output_ops)} output lines, "
            f"found {len(out_lines)}"
        )
        sys.exit(1)

    for (op_num, action), line in zip(expected_output_ops, out_lines):
        parts = line.split(" ", 1)
        if len(parts) != 2:
            print(f"FORMAT ERROR: output line must be '<opNum> <result>': {line!r}")
            sys.exit(1)
        try:
            reported_op = int(parts[0])
        except ValueError:
            print(f"FORMAT ERROR: operation number is not an integer: {line!r}")
            sys.exit(1)
        if reported_op != op_num:
            print(
                f"FORMAT ERROR: expected output for operation {op_num}, "
                f"found {reported_op}"
            )
            sys.exit(1)

        result = parts[1]
        if action == 6:
            if not (result.startswith("[") and result.endswith("]")):
                print(
                    f"FORMAT ERROR: PRINT result must be a bracketed list: {result!r}"
                )
                sys.exit(1)
        else:
            try:
                int(result)
            except ValueError:
                print(
                    f"FORMAT ERROR: result for action {action} must be an integer "
                    f"(taskId or -1): {result!r}"
                )
                sys.exit(1)

    print("FORMAT OK: output matches the expected shape for this input.")
    sys.exit(0)

if __name__ == "__main__":
    main()