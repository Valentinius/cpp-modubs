var utils_8h =
[
    [ "ModbusError", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42e", [
      [ "NO_ERROR", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42eac5c91fdff37d925c4ad1a863b5a19404", null ],
      [ "ILLEGAL_FUNCTION", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42ea349c0285766ae89d383dcc34af1d0cb4", null ],
      [ "ILLEGAL_DATA_ADDRESS", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42ea3a1430a3f4307763efadeccbf74eb17c", null ],
      [ "ILLEGAL_DATA_VALUE", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42eac085ce19fb66bb6df3b51fd8024e0d32", null ],
      [ "SLAVE_DEVICE_FAILURE", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42ea5e098e46507691e55c8db1b1ce2e5f0b", null ],
      [ "ACKNOWLEDGE", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42ea74ea67cc007ec92a872751e8c3ade516", null ],
      [ "SLAVE_DEVICE_BUSY", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42ea09dd3fe5179aa462d52f8e22cac1c21d", null ],
      [ "NEGATIVE_ACKNOWLEDGE", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42ea534a71542c7319ceb1dcebd88c0ac5c9", null ],
      [ "MEMORY_PARITY_ERROR", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42ea0c9358d9b5b8da6c4c0efe9966d875ba", null ],
      [ "GATEWAY_PATH_UNAVAILABLE", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42ea7fde5a6eb9232098b574d270f3946973", null ],
      [ "GATEWAY_TARGET_DEVICE_FAILED_TO_RESPONSE", "utils_8h.html#a8c0b52c5221ff129f554251d4860d42ea1485564a15abb5907b78da10719699f4", null ]
    ] ],
    [ "ModbusFramerType", "utils_8h.html#a99ce302c742f886581924749193c4be5", [
      [ "RTU", "utils_8h.html#a99ce302c742f886581924749193c4be5a3a61457295e70c88c908f47102c52868", null ],
      [ "ASCII", "utils_8h.html#a99ce302c742f886581924749193c4be5ab5e2cddd6610458938989aba81b2d6f2", null ],
      [ "TCP", "utils_8h.html#a99ce302c742f886581924749193c4be5a1133c80c863cfe1a87a5ffea9b609f85", null ]
    ] ],
    [ "ModbusFunction", "utils_8h.html#a840731c608991261a8d94682ab069d70", [
      [ "READ_DISCRETE_INPUTS_GROUP", "utils_8h.html#a840731c608991261a8d94682ab069d70a3f1a524a4f7598527afabae041678f08", null ],
      [ "READ_COILS_GROUP", "utils_8h.html#a840731c608991261a8d94682ab069d70a3aacadc8c8e38610f14b414e9ea3441b", null ],
      [ "READ_INPUTS_GROUP", "utils_8h.html#a840731c608991261a8d94682ab069d70af4b275cd2b3522426d50a0f0b8ff5932", null ],
      [ "READ_HOLDING_REGISTERS_GROUP", "utils_8h.html#a840731c608991261a8d94682ab069d70a21a6ee046ce208469c2a6ef3fabf96c9", null ],
      [ "WRITE_COILS_ONE", "utils_8h.html#a840731c608991261a8d94682ab069d70aa74971cc0de33a458ac72859a3755036", null ],
      [ "WRITE_COILS_GROUP", "utils_8h.html#a840731c608991261a8d94682ab069d70aae95d0aa23e9dbd312ce810835ff3c2c", null ],
      [ "WRITE_HOLDING_REGISTERS_ONE", "utils_8h.html#a840731c608991261a8d94682ab069d70a91ac7b36a82aa54bf210a895b2e71e7c", null ],
      [ "WRITE_HOLDING_REGISTERS_GROUP", "utils_8h.html#a840731c608991261a8d94682ab069d70a683e45425a3322458d14a5bd0d62a2d0", null ]
    ] ],
    [ "RegisterType", "utils_8h.html#a4b65b756b33b52a74954fa0669b86198", [
      [ "COILS", "utils_8h.html#a4b65b756b33b52a74954fa0669b86198a849ccc074302fb7c99c0d0a8bc9af0fd", null ],
      [ "DISCRETE_INPUTS", "utils_8h.html#a4b65b756b33b52a74954fa0669b86198ab25ec4c3931c76539ee2fa6b9b2eb44d", null ],
      [ "HOLDING_REGISTERS", "utils_8h.html#a4b65b756b33b52a74954fa0669b86198a99e7f2dca044825e5b497cbce598b823", null ],
      [ "INPUT_REGISTERS", "utils_8h.html#a4b65b756b33b52a74954fa0669b86198a7c1099187f875ee3f3117bab13a21c4f", null ]
    ] ],
    [ "RequestPriority", "utils_8h.html#a0bcc5fdc106dc6bc98216faa21c58b66", [
      [ "IMMEDIATE_WRITE", "utils_8h.html#a0bcc5fdc106dc6bc98216faa21c58b66a51e829d7545c5e60a96144712c6f06c2", null ],
      [ "IMMEDIATE_READ", "utils_8h.html#a0bcc5fdc106dc6bc98216faa21c58b66a8d7bab3817ce0fa4f1dc8ca464546698", null ],
      [ "WRITE", "utils_8h.html#a0bcc5fdc106dc6bc98216faa21c58b66a38aae4ca5c84132216161212d8a41caa", null ],
      [ "READ", "utils_8h.html#a0bcc5fdc106dc6bc98216faa21c58b66a1702601575d60d56cde76d27d5c7bac2", null ],
      [ "LAZY_READ", "utils_8h.html#a0bcc5fdc106dc6bc98216faa21c58b66a7bff94d72d592f2f07b188a9fcd111ce", null ]
    ] ],
    [ "RequestStatus", "utils_8h.html#a5479c4e007352f8ecb2059eb227dbeb6", [
      [ "NOT_SENT", "utils_8h.html#a5479c4e007352f8ecb2059eb227dbeb6a0cb73a7c1b491af0a43f3e338562d5a7", null ],
      [ "SENT", "utils_8h.html#a5479c4e007352f8ecb2059eb227dbeb6a00b73915fada3431153d4f16a5d57cc1", null ],
      [ "SUCCESSFULLY_RESPONSED", "utils_8h.html#a5479c4e007352f8ecb2059eb227dbeb6a7b14b45a8ae8cb365a8a6a68c7ee339d", null ],
      [ "INCORRECTLY_RESPONSED", "utils_8h.html#a5479c4e007352f8ecb2059eb227dbeb6a95e80bc374178bc5f8101f5060f6170f", null ],
      [ "TIMEOUT_ERROR", "utils_8h.html#a5479c4e007352f8ecb2059eb227dbeb6a0de339f9da0e0bdad477025a52c3e8eb", null ],
      [ "INCORRECT_REQUEST", "utils_8h.html#a5479c4e007352f8ecb2059eb227dbeb6a17ed797c609c85e1e4f438c4c3934414", null ]
    ] ],
    [ "RequestType", "utils_8h.html#ac03701c08a260f3df4eaed6edca0dfa6", [
      [ "SINGLE_REGISTER_WRITE", "utils_8h.html#ac03701c08a260f3df4eaed6edca0dfa6ae926e586c39d162b47ec0cb42bd1be3a", null ],
      [ "MULTIPLE_REGISTERS_WRITE", "utils_8h.html#ac03701c08a260f3df4eaed6edca0dfa6a7bcecb7105266459a84e1004408ceb7a", null ],
      [ "PARTIAL_REGISTER_WRITE", "utils_8h.html#ac03701c08a260f3df4eaed6edca0dfa6a226c06c6031e40d5372e9988040bcf57", null ],
      [ "SINGLE_REGISTER_READ", "utils_8h.html#ac03701c08a260f3df4eaed6edca0dfa6a08eea056a1c7a37f77b247fb95c48e0e", null ],
      [ "MULTIPLE_REGISTERS_READ", "utils_8h.html#ac03701c08a260f3df4eaed6edca0dfa6ad05a37be7392de8e170d0a9d09c8d058", null ],
      [ "PARTIAL_REGISTER_READ", "utils_8h.html#ac03701c08a260f3df4eaed6edca0dfa6ad09b915a1ae82e81d0ac2291c474f2ef", null ]
    ] ],
    [ "crcRTU", "utils_8h.html#a7c28b664f6ded864952cc973edb35e6b", null ],
    [ "fromMsbLsb", "utils_8h.html#a61d088be613ff73551a3dc0cd1c0c192", null ],
    [ "fromMsbLsb", "utils_8h.html#a419f147dcbc1cd876c43ff6a8b89ad23", null ],
    [ "toMsbLsb", "utils_8h.html#a34b2faa17849f4cc8096b09edc3d4cf4", null ],
    [ "toMsbLsb", "utils_8h.html#ab5044304a18057065cd2d7c33f78c2a9", null ]
];