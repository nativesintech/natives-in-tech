open Css;

module Colors = {
  let gray50 = hex("FAFAFA");
  let gray100 = hex("F5F5F5");
  let gray200 = hex("EEEEEE");
  let gray300 = hex("E0E0E0");
  let gray400 = hex("BDBDBD");
  let gray500 = hex("9E9E9E");
  let gray600 = hex("757575");
  let gray700 = hex("616161");
  let gray800 = hex("424242");
  let gray900 = hex("212121");

  let red50 = hex("FFEBEE");
  let red100 = hex("FFCDD2");
  let redA100 = hex("FF8A80");
  let red200 = hex("EF9A9A");
  let redA200 = hex("FF5252");
  let red300 = hex("E57373");
  let red400 = hex("EF5350");
  let redA400 = hex("FF1744");
  let red500 = hex("F44336");
  let red600 = hex("E53935");
  let red700 = hex("D32F2F");
  let redA700 = hex("D50000");
  let red800 = hex("C62828");
  let red900 = hex("B71C1C");
};

module FontSize = {
  let px12 = fontSize(px(12));
  let px14 = fontSize(px(14));
  let px16 = fontSize(px(16));
  let px18 = fontSize(px(18));
  let px20 = fontSize(px(20));
  let px24 = fontSize(px(24));
  let px30 = fontSize(px(30));
  let px36 = fontSize(px(36));
  let px48 = fontSize(px(48));
  let px60 = fontSize(px(60));
  let px72 = fontSize(px(72));
};

module Spacer = {
  let px4 = px(4);
  let px8 = px(8);
  let px12 = px(12);
  let px16 = px(16);
  let px24 = px(24);
  let px32 = px(32);
  let px48 = px(48);
  let px64 = px(64);
  let px96 = px(96);
  let px128 = px(128);
  let px192 = px(192);
  let px256 = px(256);
  let px384 = px(384);
  let px512 = px(512);
  let px640 = px(640);
  let px768 = px(768);
};

module Styles = {
  let container = [
    padding2(~h=Spacer.px64, ~v=Spacer.px48),
    media("(max-width: 600px)", [padding2(~h=Spacer.px24, ~v=Spacer.px48)]),
  ];

  let mobile = styles => media("(max-width: 600px)", styles);
};
