exist=$(python3 --version | grep "Python" | awk '{print($1)}')
if [ "$exist" = "Python" ]; then
	versionMajor=$(python3 --version | grep "Python" | awk '{print($2)}' | awk -F. '{print($1)}')
	versionMinor=$(python3 --version | grep "Python" | awk '{print($2)}' | awk -F. '{print($2)}')
	if [ "$versionMajor" -lt "3" ] || [ "$versionMinor" -lt "6" ]; then	
		echo "Python found with version: $versionMajor.$versionMinor"
		sudo apt-get install python3
	else
		echo "Already installed Python with version: $versionMajor.$versionMinor"
	fi
else
	echo "Python not found...\nDownloading Python"
	sudo apt install python3
fi
echo "\033[32mDone...\033[0m"
