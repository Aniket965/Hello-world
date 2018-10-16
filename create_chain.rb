f = File.read('/home/anirudh/bv/blogvault/blogvault/app/assets/javascripts/midnight/src/tasks/chain.json');
h = eval(f);
str = ""

h.each { |key, value|
	k = key.to_s.gsub(/\:|\"/, "").to_i
	str += "#{Task::Category.constants[k - 1].to_s} = [\n"
	value.each { |step|
		next if !Task::Step.constants[step[:id] - 1]
		str += "{:id => Task::Step::#{Task::Step.constants[step[:id] - 1].to_s}, :weightage => #{step[:weightage]}}"
		str += value.last == step ? "\n" : ",\n"
	}
	str += "]\n"
}

Task::Chain.constants.each { |const|
	str += "#{const.to_s} = [\n"
	chain = Task::Chain::class_eval(const.to_s)
	chain.each { |hash|
		str += "[Task::Step::#{Task::Step.constants[hash[:id] - 1].to_s}, #{hash[:weightage]}]"
		str += chain.last == hash ? "\n" : ",\n"
	}
	str += "]\n"
}
