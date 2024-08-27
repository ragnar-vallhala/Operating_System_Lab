pipVersion=$(pip3 --version | grep pip3 | awk '{print($1)}')

if [ "$pipVersion" = "pip" ]; then
	numpyFound=$(pip3 list | grep numpy | awk '{print($1)}')
	if [ "$numpyFound" = "numpy" ]; then
		echo "Numpy already installed. Upgrading..."
		sudo pip3 install numpy --upgrade --break-system-packages
	else
		sudo pip3 install numpy --break-system-packages
	fi
else
	sudo apt install python3-pip
	sudo pip3 install numpy --break-system-packages
fi
echo "\033[32mDone...\033[0m"

