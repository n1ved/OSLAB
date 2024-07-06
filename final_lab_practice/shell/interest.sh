echo "Enter Principal Amount : "
read p
echo "Enter Rate of Interest : "
read r
echo "Enter Time Period : "
read t

i=$((p*r*t/100))

echo "Simple Interest : $i"
echo "Seems like calculating float is not just worth it."
