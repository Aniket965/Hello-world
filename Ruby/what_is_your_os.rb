require 'os'

# Know which OS is running on your machine

if OS.windows?
  puts "OS: Windows\n Bits:#{OS.bits}\n Number of cores: #{OS.cpu_count}"
elsif OS.mac?
  puts "OS: Mac OS\n Bits:#{OS.bits}\n Number of cores: #{OS.cpu_count}"
elsif OS.linux?
  puts "OS: Linux\n Bits:#{OS.bits}\n Number of cores: #{OS.cpu_count}"
else
  puts "OS: #{OS.host_os}\n Bits:#{OS.bits}\n Number of cores: #{OS.cpu_count}"
end
