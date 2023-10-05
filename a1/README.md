% ASSIGNMENT 1
% Hy Huynh - 30087093
% October 4th, 2023

# Instructions how to run


Compile
<code>
make
</code>

Run file
<code>
./scanner test-file-name.txt
</code>

# Test cases
## Unit Test
1. test0.txt - To test operators
- **Expectation**:
 - The scanner should be able to recognize the listed operators, and interprets into English language and print them out in the following format: <line#: interpreted-operator>.
 - The scanner should recognize the conscutive operators (.e.g "<=")

2. test1.txt - To test keywords
- **Expectation**:
 - The scanner should recognize keywords and printed the following format: <line#: keyword>

3. test2.txt - To test ID, NUM
- **Expectation**:
 - The scanner should recognize ID/NUM and print in the following format: <line#: ID/NUM value>

4. test3.txt - To test comment
- **Expectation**:
 - The scanner should recognize the start and the end of the comment and print out the comment syntax as following: <line#: OCOMM/CCOMM>
 - The scanner should read the comment text and print as a whole line in the following format: <start-line#-end-line#: comment-content>

## Integration Tests
5. To test given example
This test tests the integration of each unit.
