# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "D:\\yiming\\00work\\FR685_TX_V01.X\\out\\FR752_TX\\default.cmf"
  "D:\\yiming\\00work\\FR685_TX_V01.X\\out\\FR752_TX\\default.hex"
  "D:\\yiming\\00work\\FR685_TX_V01.X\\out\\FR752_TX\\default.hxl"
  "D:\\yiming\\00work\\FR685_TX_V01.X\\out\\FR752_TX\\default.mum"
  "D:\\yiming\\00work\\FR685_TX_V01.X\\out\\FR752_TX\\default.o"
  "D:\\yiming\\00work\\FR685_TX_V01.X\\out\\FR752_TX\\default.sdb"
  "D:\\yiming\\00work\\FR685_TX_V01.X\\out\\FR752_TX\\default.sym"
  )
endif()
