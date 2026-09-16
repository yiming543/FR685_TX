# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "D:\\yiming\\00work\\FR752_TX.X\\out\\FR752_TX\\production\\default-production.cmf"
  "D:\\yiming\\00work\\FR752_TX.X\\out\\FR752_TX\\production\\default-production.hex"
  "D:\\yiming\\00work\\FR752_TX.X\\out\\FR752_TX\\production\\default-production.hxl"
  "D:\\yiming\\00work\\FR752_TX.X\\out\\FR752_TX\\production\\default-production.mum"
  "D:\\yiming\\00work\\FR752_TX.X\\out\\FR752_TX\\production\\default-production.o"
  "D:\\yiming\\00work\\FR752_TX.X\\out\\FR752_TX\\production\\default-production.sdb"
  "D:\\yiming\\00work\\FR752_TX.X\\out\\FR752_TX\\production\\default-production.sym"
  )
endif()
