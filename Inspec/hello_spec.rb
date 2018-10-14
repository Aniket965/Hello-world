#
# Thanks to http://www.anniehedgie.com/inspec-basics-1
# inspec exec hello_spec.rb
#
control 'world-1.0' do                                # A unique ID for control
  impact 1.0                                          # Just how critical is
  title 'Hello World'                                 # Readable by a human
  desc "Text should include the words 'hello world'." # Optional description
  describe file('hello.txt') do                       # The actual test
    its('content') { should match 'Hello World' }      #
  end                                                 #
end
