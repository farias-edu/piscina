find . -name "*.sh" -type f | xargs basename -s .sh

# find . -name "*.sh" ! -name ".*"  -type f -printf "%f\n" | sed 's/...$//'
