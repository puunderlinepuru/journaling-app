set -eu

FILE=$1  
if [ -f $FILE ]; then
   echo "File $FILE exists."
else
   echo "File $FILE does not exist."
   exit 1
fi

exit 0