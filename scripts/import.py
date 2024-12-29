#!/usr/bin/env python3

import argparse
import sys
import zipfile
import re
import os


def main(args: argparse.Namespace) -> int:
    zfile = args.file
    if not os.path.exists(zfile):
        error(f"Given file {zfile} does not exist.")
        return -1

    if zipfile.is_zipfile(zfile):
        with zipfile.ZipFile(zfile, "r") as z:
            z.extractall("./")
    else:
        error(f"Given file {zfile} is not a valid .zip file.")
        return -1

    remove_notion_id(os.getcwd())
    make_readme_files(os.getcwd())
    update_markdown_links(os.getcwd())

    for file in os.listdir(os.path.join(os.getcwd(), "notes")):
        os.rename(
            os.path.join(os.getcwd(), "notes", file), os.path.join(os.getcwd(), file)
        )

    os.remove(zfile)
    os.removedirs("notes")

    return 0


def remove_notion_id(path: str):
    def rename(target: str):
        dirname, basename = os.path.dirname(target), os.path.basename(target)

        basename = re.sub(r"( )[0-9a-f]{32}", "", basename).lower()
        basename = re.sub(r"\s+", "-", basename)

        os.rename(target, os.path.join(dirname, basename))

    files = os.listdir(path)
    for file in files:
        filepath = os.path.join(path, file)

        if os.path.isfile(filepath) and file.endswith(".md") and file != "README.md":
            rename(filepath)
        elif os.path.isdir(filepath):
            remove_notion_id(filepath)

    rename(path)


def make_readme_files(path: str):
    files = os.listdir(path)
    pairs: list[tuple[str, str]] = []
    for file in files:
        filepath = os.path.join(path, file)

        if os.path.isdir(filepath):
            if (file + ".md") in files:
                pairs.append((filepath, os.path.join(path, file + ".md")))

            make_readme_files(filepath)

    for directory, file in pairs:
        os.rename(file, os.path.join(directory, "README.md"))


def update_markdown_links(path: str):
    def get_updated_contents(contents: str) -> str:
        result, found_link = "", ""
        found_brackets_count, found_parens_count = 0, 0

        for ch in contents:
            match ch:
                case "[":
                    found_brackets_count = 1

                case "]":
                    if found_brackets_count == 1:
                        found_brackets_count = 2
                    else:
                        found_brackets_count = 0

                case "(":
                    if (
                        found_brackets_count == 2
                        and len(result) > 0
                        and result[-1] == "]"
                    ):
                        found_parens_count = 1
                    else:
                        found_brackets_count = 0
                        found_parens_count = 0

                case ")":
                    found_link = re.sub(r"(%20)[0-9a-f]{32}", "", found_link).lower()
                    found_link = re.sub(r"%20", "-", found_link)
                    link_parts = found_link.split("/")

                    if len(link_parts) > 0:
                        found_link = "/".join(link_parts[1:])

                    if os.path.exists(
                        os.path.join(path, found_link.replace(".md", ""), "README.md")
                    ):
                        found_link = found_link.replace(".md", "")

                    result += found_link

                    found_link = ""

                    found_brackets_count = 0
                    found_parens_count = 0

            if found_brackets_count == 2 and found_parens_count == 1 and ch != "(":
                found_link += ch
            else:
                result += ch

        result += found_link
        return result

    files = os.listdir(path)
    for file in files:
        filepath = os.path.join(path, file)

        if os.path.isdir(filepath):
            update_markdown_links(filepath)
        elif os.path.isfile(filepath) and file.endswith(".md"):
            with open(filepath, "r") as f:
                contents = f.read()

            contents = get_updated_contents(contents)

            with open(filepath, "w") as f:
                f.write(contents)


def error(message: str):
    print(message, file=sys.stderr)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-f", "--file", help="The .zip file to import.", required=True)

    args = parser.parse_args()
    exit(main(args))
