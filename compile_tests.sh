#   Script to automate test file compilation
#   Acquire file names
file_names=`ls ./tests/`
suffix=".cpp"
for file_name in $file_names
do
    if [[ "$file_name" == *cpp ]]
    then
        trimmed_name=${file_name::-4}
        object_name="./tests/${trimmed_name}.out"
        file_name="./tests/${file_name}"
        g++ $file_name -o $object_name
        echo "Compiled test $trimmed_name"        
    fi
done