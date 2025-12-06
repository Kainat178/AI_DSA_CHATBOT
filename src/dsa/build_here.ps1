# build_here.ps1 — compile a single source file in this directory using the project include root
# Usage: .\build_here.ps1 Trie.cpp    # will create Trie.exe next to the source

param(
    [Parameter(Mandatory=$true)] [string]$file
)

$srcDir = Split-Path -Parent $MyInvocation.MyCommand.Definition
$projectRoot = Resolve-Path "$srcDir\..\.."
$includeDir = Join-Path $projectRoot 'include'
$srcPath = Join-Path $srcDir $file

if (-not (Test-Path $srcPath)) {
    Write-Error "Source file not found: $srcPath"
    exit 1
}

$exe = [System.IO.Path]::ChangeExtension($srcPath, '.exe')
$cmd = "g++ `"$srcPath`" -I`"$includeDir`" -o `"$exe`""
Write-Host "Running: $cmd"
cmd /c $cmd
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "Built: $exe"
