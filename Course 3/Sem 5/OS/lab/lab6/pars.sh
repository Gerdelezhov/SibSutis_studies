readelf -s libstudents.so |
  awk '/(FUNC|GLOBAL)/ {print $0}' |
  sort -k 3 -r |
  uniq -f 2 |
  awk 'BEGIN {
    printf "%-20s %-8s %-8s %-6s %-7s %-6s %s\n", "Value", "Size", "Type", "Bind", "Vis", "Ndx", "Name"
  } {
    printf "%-20s %-8s %-8s %-6s %-6s %-6s %s\n", $2, $3, $4, $5, $6, $7, $8
  }'
