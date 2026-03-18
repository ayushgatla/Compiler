#!/bin/bash

COMPILER="./compiler"
TESTDIR="./testcases"

PASSED=0
FAILED=0

PASSED_TESTS=()
FAILED_TESTS=()

echo "===================================="
echo "Building Compiler"
echo "===================================="

flex lexer.l
bison -d parser.y
gcc lex.yy.c parser.tab.c ast.c ir.c symbol.c -o compiler

if [ ! -f "$COMPILER" ]; then
    echo "Compiler build failed"
    exit 1
fi

echo ""
echo "===================================="
echo "Running Compiler Test Suite"
echo "===================================="

for file in "$TESTDIR"/*.txt
do
    echo ""
    echo "------------------------------------"
    echo "Running test: $file"
    echo "------------------------------------"

    OUTPUT=$("$COMPILER" < "$file")

    echo "$OUTPUT"

    if echo "$OUTPUT" | grep -q "Parsing failed"; then
        echo "Result: FAILED (Parser error)"
        ((FAILED++))
        FAILED_TESTS+=("$file")
        continue
    fi

    echo ""
    echo "Compiling generated C program..."
    gcc output.c -o program

    if [ $? -ne 0 ]; then
        echo "Result: FAILED (C compilation error)"
        ((FAILED++))
        FAILED_TESTS+=("$file")
        continue
    fi

    echo ""
    echo "Running program:"
    ./program

    echo ""
    echo "Result: PASSED"

    ((PASSED++))
    PASSED_TESTS+=("$file")

done

echo ""
echo "===================================="
echo "Test Summary"
echo "===================================="

echo "Total tests : $((PASSED + FAILED))"
echo "Passed      : $PASSED"
echo "Failed      : $FAILED"

echo ""
echo "------------ PASSED TESTS ----------"

for t in "${PASSED_TESTS[@]}"
do
    echo "$t"
done

echo ""
echo "------------ FAILED TESTS ----------"

for t in "${FAILED_TESTS[@]}"
do
    echo "$t"
done

echo ""
echo "===================================="

if [ $FAILED -eq 0 ]; then
    echo "All tests passed"
else
    echo "Some tests failed"
fi
