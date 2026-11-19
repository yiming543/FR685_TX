# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "D:\\yiming\\00work\\FR685_TX_V02.X\\out\\FR685_TX_V02\\default.cmf"
  "D:\\yiming\\00work\\FR685_TX_V02.X\\out\\FR685_TX_V02\\default.hex"
  "D:\\yiming\\00work\\FR685_TX_V02.X\\out\\FR685_TX_V02\\default.hxl"
  "D:\\yiming\\00work\\FR685_TX_V02.X\\out\\FR685_TX_V02\\default.mum"
  "D:\\yiming\\00work\\FR685_TX_V02.X\\out\\FR685_TX_V02\\default.o"
  "D:\\yiming\\00work\\FR685_TX_V02.X\\out\\FR685_TX_V02\\default.sdb"
  "D:\\yiming\\00work\\FR685_TX_V02.X\\out\\FR685_TX_V02\\default.sym"
  )
endif()
