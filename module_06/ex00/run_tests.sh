

while IFS= read -r line
do
	printf "\e[33m>>> $line \e[0m\n"
	$line
	echo
done < test_cases.txt