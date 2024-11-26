GREEN='\033[1;32m'
BLUE='\033[1;34m'
RED='\033[1;31m'
NC='\033[0m'

program_name="./RPN"

valgrind="valgrind --leak-check=full --show-leak-kinds=all"

if [ "$1" == "-v" ]; then
    echo -e "${GREEN}Valgrind tests:${NC}"
    v_state=0
else
    echo -e "${GREEN}Normal tests:${NC}"
    v_state=1
fi

tests=("2 3 + 4 5 + * 6 7 + * 8 9 + *"
"2 2 2 2 2 2 2 2 2 2 * * * * *    * * * *"
"9 1 + 2 2 - - 3 2 * * 6 2         / / 5 3 - +"
"1 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 *"
"8 4 / 6 * 3 / 7 * 9 / 2 *"
"2 3 4 * + 5 6 7 * + + 8 9 * +"
"1 1    + 2 + 3 + 4     + 5 + 6 + 7 + 8 + 9 +"
"1 9 * 2 + 3 8 *    + 4 7    * + 5 6 * +"
"0 5 /"
"5 0 /"
)

answers=("9945" "1024" "22" "362880" "6.222222222222222" "133" "46" "93")

echo -e "${GREEN}Correct tests:${NC}"
for i in ${!tests[@]}; do
    echo -e "${GREEN}Test ${BLUE}$i${NC}"
    echo -e "${GREEN}Input: ${BLUE}'${tests[$i]}'${NC}"
    echo -e "${GREEN}Expected: ${BLUE}${answers[$i]}${NC}"
    if [ $v_state -eq 0 ]; then
        echo -n -e "${GREEN}Output: "
        echo -e "${BLUE}$($valgrind $program_name "${tests[$i]}")${NC}"
    else
        echo -n -e "${GREEN}Output: "
        echo -e "${BLUE}$($program_name "${tests[$i]}")${NC}"
    fi
    echo
done

wrong_tests=("1 2 3 +" 
"1 2 + 3" 
"1 + 2 3" 
"1 + 2 + 3" 
"" 
" " 
"'1' '2' '+'" 
"123 4 +"
"123 4 + + +"
"1 2 3 ++"
"1 23 --"
"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15"
"a b c +"
"'''''"
)

echo -e "${GREEN}Wrong tests:${NC}"
for i in ${!wrong_tests[@]}; do
    echo -e "${GREEN}Test ${BLUE}$i${NC}"
    echo -e "${GREEN}Input: ${BLUE}'${wrong_tests[$i]}'${NC}"
    echo -e "${GREEN}Expected: ${RED}Error${NC}"
    if [ $v_state -eq 0 ]; then
        echo -n -e "${GREEN}Output: "
        echo -e "${RED}$($valgrind $program_name "${wrong_tests[$i]}")${NC}"
    else
        echo -n -e "${GREEN}Output: "
        echo -e "${RED}$($program_name "${wrong_tests[$i]}")${NC}"
    fi
    echo
done

