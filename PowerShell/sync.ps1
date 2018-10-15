$ErrorActionPreference = "Stop"
$currentDrivesLength = (Get-PSDrive -PSProvider FileSystem).Count
$doneFirstCheck = $false
while($true){
    $allDrives = Get-PSDrive -PSProvider FileSystem
    $possibleDrives = @()
    
    if($allDrives.Count -notlike $currentDrivesLength -or !$doneFirstCheck -or $possibleDrives.Count -gt 0){
        $startDate = Get-Date

        for($i = 0; $i -lt $allDrives.Count;$i++){
            if($allDrives[$i] -like 'C' -or $allDrives[$i] -like 'D' -or $allDrives[$i] -like 'W' -or $allDrives[$i] -like 'Y'){
                Write-Host "[INFO] Skipped system drive: $($allDrives[$i])" -ForegroundColor Yellow
            }
            else{
                Write-Host "[INFO] Found external drive: $($allDrives[$i])" -ForegroundColor Green
                $possibleDrives += $allDrives[$i];
            }
        }
        Write-Host "[INFO] Found $($possibleDrives.Count) external drives" -ForegroundColor White
        if($possibleDrives.Count -gt 0){
            $path = "C:\Users\luca6\OneDrive\Documenti\"
            if(Test-Path $path){
                Write-Host "[SUCCESS] Found data" -ForegroundColor Green
                for($i = 0; $i -lt $possibleDrives.Count; $i++){
                    if(Test-Path $possibleDrives[$i].Root){
                        Write-Host "[SUCCESS] Backup path found" -ForegroundColor Green
                        Write-Host "[INFO] Start copying files from [$($path)] to [$($possibleDrives[$i])]" -ForegroundColor Gray
                        Copy-Item -Path $path -Destination $possibleDrives[$i].Root -Recurse -InformationAction Stop
                    }
                    else{
                        Write-Host "[ERROR] Invalid path for backup" -ForegroundColor Red
                    } 
                }
            }
            else{
                Write-Host "[ERROR] Invalid data path" -ForegroundColor Red
            }

            $dateFinish = Get-Date
            $dateDiff = $dateFinish - $startDate 
            Write-Host "[FINISHED BACKUP $($dateFinish)] Finished in $($dateDiff.Milliseconds) ms" -ForegroundColor Green        }
        else{
            Write-Host "[ERROR] Found any external drive" -ForegroundColor Red
        }
        $doneFirstCheck = $true
        sleep(5);

        $currentDrivesLength = (Get-PSDrive -PSProvider FileSystem).Count
    }
    else{
        $sleepTime = 3;
        clear
        Write-Host "[RADAR] Next check in $($sleepTime) seconds.." -ForegroundColor Gray 
        sleep($sleepTime);
    }
}
