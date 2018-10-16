def return_type(type)
	case type
	when "site", "account", "snap", "task", "user"
		return "ImmutablePropTypes.map"
	when "sites", "notices", "restores", "tasks", "modals", "notifications", "snapshots", "subscriptions", "steps"
		return "ImmutablePropTypes.list"
	when "limit", "version"
		return "PropTypes.number"
	when "cache", "user_au_info", "account_au_info"
		return "ImmutablePropTypes.map"
	when "location", "router", "params", "actions", "versions", "route", "style"
		return "PropTypes.object"
	when "routes"
		return "PropTypes.array"
	when "title", "dropboxEmail", "description", "name", "placeholder", "className", "icon",
					"classname", "message", "msg"
		return "PropTypes.string"
	else
		return "PropTypes.func"
	end
end

def im_type(arr)
	immutable_types = ["task", "sites", "notices", "restores", "tasks", "modals", "notifications",
											"snapshots", "site", "account", "snap", "cache", "user_au_info", "account_au_info", "limit"]
	return !(immutable_types & arr).empty?
end

def props_init(file)
	arr = []
	matches = file.scan(/const \{.*\} \= this\.props/)
	matches.each { |m|
		arr << m.scan(/\{.*\}/).first.gsub(/[\{ \}]/, "").split(',')
	}
	arr = arr.flatten.compact.uniq
	puts "const {} : #{arr.inspect}"
	arr
end

def directly_used_props(file)
	arr = []
	matches = file.scan(/this.props\.[a-zA-Z0-9]*/)
	matches.uniq!
	matches.each { |m|
		arr << m.gsub(/this\.props\./, "")
	}
	arr = arr.compact.uniq
	puts "this.props : #{arr.inspect}"
	arr
end

def find_component(file)
	file.scan(/class .* extends/).first.gsub(/(class )|( extends)/, "")
end

path = gets
file = File.read(path.chomp)

arr = props_init(file) + directly_used_props(file)
arr = arr.compact.uniq
component = find_component(file)

str = "#{component}.propTypes = {\n\t"
arr.each { |a|
	if a == arr.last
		str += "#{a}: #{return_type(a)}\n}"
	else
		str += "#{a}: #{return_type(a)},\n\t"
	end
}

s = file.clone
index = s.index(/\n\}\n\n/)
s[index + 3] += "#{str}\n\n"

ind = file.index(/class/)
im_s = "import PropTypes from 'prop-types'\n"
im_s += "import ImmutablePropTypes from 'react-immutable-proptypes'\n" if im_type(arr)
s[ind - 2] += im_s

s.gsub!(/ == /, " === ")
s.gsub!(/ != /, " !== ")

File.open(path.chomp, 'w+') { |f| f.write(s) }
