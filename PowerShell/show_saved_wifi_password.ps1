#Show saved wifi passwords
#Supported languages: ENG,GER -> feel free to add your language
Write-Host "To be able to read the keys you need to run this script as administrator!";
Write-Host "Listing all saved wifi profiles...";
sleep 1;
netsh wlan show profiles
Write-Host "Please choose a wifi network from the list.";
$name = Read-Host "Type the name";
Write-Host "You have chosen: $name.";
sleep 1;
Write-Host "The stored wifi password for $name is:";

$system_lang = Get-Culture;
$system_lang = $system_lang.name;

if($system_lang -eq "en-US"){
    netsh wlan show profile name="$name" key=clear | findstr -I -N "Key Content";
}
elseif($system_lang -eq "de-DE"){
    netsh wlan show profile name="$name" key=clear | findstr -I -N "Schlüsselinhalt";
}
else{
    Write-Host "Language not supportet.";
}
