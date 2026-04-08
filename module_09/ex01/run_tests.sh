

while IFS= read -r line
do
	printf "\e[33m>>> ./RPN "%s"\e[0m\n" "$line"

	./RPN "$line"
	echo
done < test_cases.txt

printf "\e[33m>>> ./RPN 8 9 * 9 - 9 - 9 - 4 - 1 +  \e[0m\n"
./RPN 8 9 * 9 - 9 - 9 - 4 - 1 + 
echo

printf "\e[33m>>> ./RPN \e[0m\n"
./RPN
echo