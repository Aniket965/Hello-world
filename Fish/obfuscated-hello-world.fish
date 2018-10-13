#!/usr/bin/env fish

set x (printf 'G1szbXNtYXNoG1swbSB0aGF0IG1mIGxpa2UgYnV0dG9uIPCfmKnwn5GM' | base64 -d)
for char in (string split '' $x)
	grep -Faom 1 $char /dev/urandom | head -n 1 | tr -d '\n'
end
echo
