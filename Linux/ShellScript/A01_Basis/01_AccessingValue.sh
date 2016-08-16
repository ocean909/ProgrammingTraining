#!/bin/bash
#Description: Basic variable

book="Linux Shell Scripting"
#point 1: constant variable
readonly writer="Jon"
total_chapters=8
number_of_pages=210
average_pages_per_chapter=26.25

echo "Book name - $book"
echo "Writer - $writer"
echo "Number of Chapters - $total_chapters"
printf "Total number of pages in book - $number_of_pages\n"
printf "Average pages in each chapter - %-.2f\n" $average_pages_per_chapter

#point 2: cancel the value
unset total_chapters
echo "Number of Chapters - $total_chapters"

book="Windows Bat file"
echo "Book name - $book"
writer="Mary"
echo "Writer - $writer"

#point 3: read user input
echo "Do you like this book?"
read text
echo "user say: $text"
read -p "Really?" check
echo "user say again: $check"
