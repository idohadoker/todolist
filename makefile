all:
	gcc task.c list.c main.c -o main
github:
	git init
	git add .
	git commit -m "upload"
	git push origin master --force