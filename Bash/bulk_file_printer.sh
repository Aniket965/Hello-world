
read -p "File extension: " ext;
for i in $(ls -l | wc -l)
do cat $(ls | grep $ext)
done

