name=$(whoami)
num=1
echo "hello $name"
echo $((num+1))

str="this is a string"
echo "${str/i/1}"
echo "${somethingthatsundefined:-defaultStuff}"

int1=1
int2=2
echo $((int1+int2))

echo $name $str
