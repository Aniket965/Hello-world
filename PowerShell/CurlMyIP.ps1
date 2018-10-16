<#
.Synopsis
    Prints the public IP address of the localhost
.DESCRIPTION
    The following command returns the public IP address of the localhost by looking up the
    OpenDNS MyIP subdomain which returns information about the IP address that looked up said
    domain.
#>

([system.net.dns]::GetHostAddresses("myip.opendns.com")).ipaddresstostring
