Filename=$1
declare -a Stack 
declare -a Colors=('#eecc80', '#ccee80', '#80ccee', '#eecc80', '#80eecc')
declare -a Shapes=('box', 'ellipse', 'octagon', 'hexagon', 'diamond')

echo "digraph G {
node [peripheries=2 style=\"filled,rounded\" fontname=\"Vera Sans Mono\" color=\"#eecc80\"];
rankdir=LR;
label=\"$Filename\"
main [shape=box];"
LastLevel=0
LastFunc="main"
ContextFunc="main"
cflow "$Filename" -l |
tail -n +2 |
while read line
do
	Level="$(echo $line | grep -Po '[0-9]+(?=})')"
	Func="$(echo $line | grep -Po '[a-zA-Z0-9_-]+(?=\()')"
	if [[ "$Level" > "$LastLevel" ]]
	then
		Stack[$LastLevel]=$LastFunc
		ContextFunc="$LastFunc"
		Index=$(($Level%5))
		echo "node [color=\"${Colors[$Index]}\" shape=\"${Shapes[$Index]}\"];edge [color=\"${Colors[$Index]}\"];"
	elif [[ "$Level" < "$LastLevel" ]] 
	then
		ContextFunc=${Stack[$(($Level-1))]}
		Index=$(($Level%5))
		echo "node [color=\"${Colors[$Index]}\" shape=\"${Shapes[$Index]}\"];edge [color=\"${Colors[$Index]}\"];"
	fi
	echo "$ContextFunc -> $Func;"
	LastFunc="$Func"
	LastLevel="$Level"
done
echo "}"
