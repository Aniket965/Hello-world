$theWord = "Hello World"

$enterName = Write-Host "Please Enter Your Name :)"
$name = Read-Host
$repeat = 0

    while(!$name)
        {
            $repeat ++
                if($repeat -le 2){echo "Come on"}
                elseif($repeat -eq 3){echo "Please just enter your name... :("}
                elseif($repeat -eq 4){ echo "Please..."}
                else{ echo "DO WHAT EVER YOU WANT :')"}
                $name = Read-Host
        }
    if($repeat -eq 0){Write-Host -ForegroundColor Green "$theWord and Hello $name"}
    elseif($repeat -lt 10){Write-Host -ForegroundColor Magenta "$theWord and Hello $name, you've make me repeat $repeat times.. :)"}
    else{Write-Host -ForegroundColor Red "$theWord and Hello $name you've make me repeat $repeat times.. :'( thanks for that"}


Read-Host