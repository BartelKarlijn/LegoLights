for /L %i in (50,1,250) do @(
    for /f %s in ('curl -s -o nul -w "%%{http_code}" http://192.168.68.%i') do (
        if not "%s"=="000" echo 192.168.68.%i → HTTP %s
    )
)
