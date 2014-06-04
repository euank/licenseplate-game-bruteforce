var allThreeLetterCombos = [];
var alphebet = "abcdefghijklmnopqrstuvwxyz";

for(var i=0;i<26;i++) {
   for (var j=0;j<26;j++) {
      for(var k=0;k<26;k++) {
	 allThreeLetterCombos.push(alphebet[i] + alphebet[j] + alphebet[k]);
      }
   }
}

var file = require('fs').readFileSync('/usr/share/dict/words', 'utf8');
var lines = file.split("\n");
var output = "";
for(var i=0;i<lines.length;i++){
   lines[i] = lines[i].toLowerCase();
}

for(var i=0;i<allThreeLetterCombos.length;i++) {
   var shortest = null;
   for(var j=0;j<lines.length;j++) {
      if(areInOrder(allThreeLetterCombos[i], lines[j])) {
	 if(shortest == null || shortest.length > lines[j].length) {
	    shortest = lines[j];
	 }
      }
   }
   if(shortest != null) output += allThreeLetterCombos[i] + " - " + shortest + "\n";
   else console.log("" + allThreeLetterCombos[i]);
}

require('fs').writeFileSync('out.txt', output);

function areInOrder(three, word) {
   var ndx = 0;
   for(var i=0;i<word.length;i++) {
      if(three[ndx] == word[i]) {
	 ndx++;
      }
      if(ndx == 3) return true;
   }
   return false;
}
