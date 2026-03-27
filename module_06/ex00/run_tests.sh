while IFS= read -r line
do
	echo ">>> $line"
	$line
	echo
done < test_cases.txt