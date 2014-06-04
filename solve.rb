words = File.read('/usr/share/dict/words').split("\n");

longest_word = words.reduce{|x,y| x.length < y.length ? y : x}
impossibly_long_word = longest_word + 'x'

license_plates = ('a'..'z').to_a.repeated_permutation(3).map(&:join)
shortest_plates = Hash[license_plates.collect{|p| [p, impossibly_long_word]}]


words.each do |word|
  word.chars.combination(3).each do |plate|
    plate = plate.join.downcase
    shortest_plates[plate] = word if word.length < shortest_plates[plate].length
  end
end


impossible_plates = shortest_plates.select{|k,v| v == impossibly_long_word}

shortest_plates.reject!{|k,v| v == impossibly_long_word}

File.write("impossible_plates.txt", impossible_plates.keys.sort.join("\n"))
File.write("plate_solutions.txt", shortest_plates.map{|k,v| "#{k} => #{v}"}.sort.join("\n"))
