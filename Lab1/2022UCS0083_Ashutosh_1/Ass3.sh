if [ $# -ne 2 ]; then
	echo "Usage: $0 <command> <filepath>"
else
	$1 2>&1 | tee $2
fi
echo "\033[32mDone...\033[0m"
