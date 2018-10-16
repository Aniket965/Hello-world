# Node default will run on any Puppet host that isn't caught by another node target
node default {
    # Debug output on the Puppet Master (if in master - client setup)
    notice('Hello World! on the Puppet Master')

    # Debug output on the Puppet Client
    notify { 'Hello World! on the Puppet Client':}
}
