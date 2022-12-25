/*
 * value_lookup.h
 *
 *  Created on: Dec 25, 2022
 *      Author: Stuart
 */

#ifndef INC_SYNTH_INTERFACE_VALUE_LOOKUP_H_
#define INC_SYNTH_INTERFACE_VALUE_LOOKUP_H_

typedef struct
{

  unsigned char * name;
  unsigned char maximum;

} PARAM_INFO;

PARAM_INFO code xva_lookup[] =
  {
      //oscillators
        { "", 0xFF }, //0
        { "OSC1_CTRL", 1 }, //1
        { "OSC2_CTRL", 1 },//2
        { "OSC3_CTRL", 1 },//3
        { "OSC4_CTRL", 1 },//4
        { "OSC_SYNC", 0xF },//5
        { "OSC_MODE", 0xFF },//6
        { "OSC1_PHASE", 3 },//7
        { "OSC2_PHASE", 3 },//8
        { "OSC3_PHASE", 3 },//9
        { "OSC4_PHASE", 3 },//10
        { "OSC1_WFORM", 8 },//11
        { "OSC2_WFORM", 8 },//12
        { "OSC3_WFORM", 8 },//13
        { "OSC4_WFORM", 8 },//14
        { "OSC1_PWIDTH", 0xFF },//15
        { "OSC2_PWIDTH", 0xFF },//16
        { "OSC3_PWIDTH", 0xFF },//17
        { "OSC4_PWIDTH", 0xFF },//18
        { "OSC1_TSPOSE", 0xFF },//19
        { "OSC2_TSPOSE", 0xFF },//20
        { "OSC3_TSPOSE", 0xFF },//21
        { "OSC4_TSPOSE", 0xFF },//22
        { "", 0xFF },//23
        { "", 0xFF },//24
        { "", 0xFF },//25
        { "", 0xFF },//26
        { "", 0xFF },//27
        { "", 0xFF },//28
        { "", 0xFF },//29
        { "", 0xFF },//30
        { "", 0xFF },//31
        { "", 0xFF },//32
        { "", 0xFF },//33
        { "", 0xFF },//34
        { "", 0xFF },//35
        { "", 0xFF },//36
        { "", 0xFF },//37
        { "", 0xFF },//38
        { "", 0xFF },//39
        { "", 0xFF },//40
        { "", 0xFF },//41
        { "", 0xFF },//42
        { "", 0xFF },//43
        { "", 0xFF },//44
        { "", 0xFF },//45
        { "", 0xFF },//46
        { "", 0xFF },//47
        { "", 0xFF },//48
        { "", 0xFF },//49
        { "", 0xFF },//50
        { "", 0xFF },//51
        { "", 0xFF },//52
        { "", 0xFF },//53
        { "", 0xFF },//54
        { "", 0xFF },//55
        { "", 0xFF },//56
        { "", 0xFF },//57
        { "", 0xFF },//58
        { "", 0xFF },//59
        { "", 0xFF },//60
        { "", 0xFF },//61
        { "", 0xFF },//62
        { "", 0xFF },//63
        { "", 0xFF },//64
        { "", 0xFF },//65
        { "", 0xFF },//66
        { "", 0xFF },//67
        { "", 0xFF },//68
        { "", 0xFF },//69
        { "", 0xFF },//70
        { "", 0xFF },//71
        { "", 0xFF },//72
        { "", 0xFF },//73
        { "", 0xFF },//74
        { "", 0xFF },//75
        { "", 0xFF },//76
        { "", 0xFF },//77
        { "", 0xFF },//78
        { "", 0xFF },//79
        { "", 0xFF },//80
        { "", 0xFF },//81
        { "", 0xFF },//82
        { "", 0xFF },//83
        { "", 0xFF },//84
        { "", 0xFF },//85
        { "", 0xFF },//86
        { "", 0xFF },//87
        { "", 0xFF },//88
        { "", 0xFF },//89
        { "", 0xFF },//90
        { "", 0xFF },//91
        { "", 0xFF },//92
        { "", 0xFF },//93
        { "", 0xFF },//94
        { "", 0xFF },//95
        { "", 0xFF },//96
        { "", 0xFF },//97
        { "", 0xFF },//98
        { "", 0xFF },//99

      //100

        { "", 0xFF },//100
        { "", 0xFF },//101
        { "", 0xFF },//102
        { "", 0xFF },//103
        { "", 0xFF },//104
        { "", 0xFF },//105
        { "", 0xFF },//106
        { "", 0xFF },//107
        { "", 0xFF },//108
        { "", 0xFF },//109
        { "", 0xFF },//110
        { "", 0xFF },//111
        { "", 0xFF },//112
        { "", 0xFF },//113
        { "", 0xFF },//114
        { "", 0xFF },//115
        { "", 0xFF },//116
        { "", 0xFF },//117
        { "", 0xFF },//118
        { "", 0xFF },//119
        { "", 0xFF },//120
        { "", 0xFF },//121
        { "", 0xFF },//122
        { "", 0xFF },//123
        { "", 0xFF },//124
        { "", 0xFF },//125
        { "", 0xFF },//126
        { "", 0xFF },//127
        { "", 0xFF },//128
        { "", 0xFF },//129
        { "", 0xFF },//130
        { "", 0xFF },//131
        { "", 0xFF },//132
        { "", 0xFF },//133
        { "", 0xFF },//134
        { "", 0xFF },//135
        { "", 0xFF },//136
        { "", 0xFF },//137
        { "", 0xFF },//138
        { "", 0xFF },//139
        { "", 0xFF },//140
        { "", 0xFF },//141
        { "", 0xFF },//142
        { "", 0xFF },//143
        { "", 0xFF },//144
        { "", 0xFF },//145
        { "", 0xFF },//146
        { "", 0xFF },//147
        { "", 0xFF },//148
        { "", 0xFF },//149
        { "", 0xFF },//150
        { "", 0xFF },//151
        { "", 0xFF },//152
        { "", 0xFF },//153
        { "", 0xFF },//154
        { "", 0xFF },//155
        { "", 0xFF },//156
        { "", 0xFF },//157
        { "", 0xFF },//158
        { "", 0xFF },//159
        { "", 0xFF },//160
        { "", 0xFF },//161
        { "", 0xFF },//162
        { "", 0xFF },//163
        { "", 0xFF },//164
        { "", 0xFF },//165
        { "", 0xFF },//166
        { "", 0xFF },//167
        { "", 0xFF },//168
        { "", 0xFF },//169
        { "", 0xFF },//170
        { "", 0xFF },//171
        { "", 0xFF },//172
        { "", 0xFF },//173
        { "", 0xFF },//174
        { "", 0xFF },//175
        { "", 0xFF },//176
        { "", 0xFF },//177
        { "", 0xFF },//178
        { "", 0xFF },//179
        { "", 0xFF },//180
        { "", 0xFF },//181
        { "", 0xFF },//182
        { "", 0xFF },//183
        { "", 0xFF },//184
        { "", 0xFF },//185
        { "", 0xFF },//186
        { "", 0xFF },//187
        { "", 0xFF },//188
        { "", 0xFF },//189
        { "", 0xFF },//190
        { "", 0xFF },//191
        { "", 0xFF },//192
        { "", 0xFF },//193
        { "", 0xFF },//194
        { "", 0xFF },//195
        { "", 0xFF },//196
        { "", 0xFF },//197
        { "", 0xFF },//198
        { "", 0xFF },//199
      //200
        { "", 0xFF },//200
        { "", 0xFF },//201
        { "", 0xFF },//202
        { "", 0xFF },//203
        { "", 0xFF },//204
        { "", 0xFF },//205
        { "", 0xFF },//206
        { "", 0xFF },//207
        { "", 0xFF },//208
        { "", 0xFF },//209
        { "", 0xFF },//210
        { "", 0xFF },//211
        { "", 0xFF },//212
        { "", 0xFF },//213
        { "", 0xFF },//214
        { "", 0xFF },//215
        { "", 0xFF },//216
        { "", 0xFF },//217
        { "", 0xFF },//218
        { "", 0xFF },//219
        { "", 0xFF },//220
        { "", 0xFF },//221
        { "", 0xFF },//222
        { "", 0xFF },//223
        { "", 0xFF },//224
        { "", 0xFF },//225
        { "", 0xFF },//226
        { "", 0xFF },//227
        { "", 0xFF },//228
        { "", 0xFF },//229
        { "", 0xFF },//230
        { "", 0xFF },//231
        { "", 0xFF },//232
        { "", 0xFF },//233
        { "", 0xFF },//234
        { "", 0xFF },//235
        { "", 0xFF },//236
        { "", 0xFF },//237
        { "", 0xFF },//238
        { "", 0xFF },//239
        { "", 0xFF },//240
        { "", 0xFF },//241
        { "", 0xFF },//242
        { "", 0xFF },//243
        { "", 0xFF },//244
        { "", 0xFF },//245
        { "", 0xFF },//246
        { "", 0xFF },//247
        { "", 0xFF },//248
        { "", 0xFF },//249
        { "", 0xFF },//250
        { "", 0xFF },//251
        { "", 0xFF },//252
        { "", 0xFF },//253
        { "", 0xFF },//254
        { "", 0xFF },//255
        { "", 0xFF },//256
        { "", 0xFF },//257
        { "", 0xFF },//258
        { "", 0xFF },//259
        { "", 0xFF },//260
        { "", 0xFF },//261
        { "", 0xFF },//262
        { "", 0xFF },//263
        { "", 0xFF },//264
        { "", 0xFF },//265
        { "", 0xFF },//266
        { "", 0xFF },//267
        { "", 0xFF },//268
        { "", 0xFF },//269
        { "", 0xFF },//270
        { "", 0xFF },//271
        { "", 0xFF },//272
        { "", 0xFF },//273
        { "", 0xFF },//274
        { "", 0xFF },//275
        { "", 0xFF },//276
        { "", 0xFF },//277
        { "", 0xFF },//278
        { "", 0xFF },//279
        { "", 0xFF },//280
        { "", 0xFF },//281
        { "", 0xFF },//282
        { "", 0xFF },//283
        { "", 0xFF },//284
        { "", 0xFF },//285
        { "", 0xFF },//286
        { "", 0xFF },//287
        { "", 0xFF },//288
        { "", 0xFF },//289
        { "", 0xFF },//290
        { "", 0xFF },//291
        { "", 0xFF },//292
        { "", 0xFF },//293
        { "", 0xFF },//294
        { "", 0xFF },//295
        { "", 0xFF },//296
        { "", 0xFF },//297
        { "", 0xFF },//298
        { "", 0xFF },//299
      //300
        { "", 0xFF },//300
        { "", 0xFF },//301
        { "", 0xFF },//302
        { "", 0xFF },//303
        { "", 0xFF },//304
        { "", 0xFF },//305
        { "", 0xFF },//306
        { "", 0xFF },//307
        { "", 0xFF },//308
        { "", 0xFF },//309
        { "", 0xFF },//310
        { "", 0xFF },//311
        { "", 0xFF },//312
        { "", 0xFF },//313
        { "", 0xFF },//314
        { "", 0xFF },//315
        { "", 0xFF },//316
        { "", 0xFF },//317
        { "", 0xFF },//318
        { "", 0xFF },//319
        { "", 0xFF },//320
        { "", 0xFF },//321
        { "", 0xFF },//322
        { "", 0xFF },//323
        { "", 0xFF },//324
        { "", 0xFF },//325
        { "", 0xFF },//326
        { "", 0xFF },//327
        { "", 0xFF },//328
        { "", 0xFF },//329
        { "", 0xFF },//330
        { "", 0xFF },//331
        { "", 0xFF },//332
        { "", 0xFF },//333
        { "", 0xFF },//334
        { "", 0xFF },//335
        { "", 0xFF },//336
        { "", 0xFF },//337
        { "", 0xFF },//338
        { "", 0xFF },//339
        { "", 0xFF },//340
        { "", 0xFF },//341
        { "", 0xFF },//342
        { "", 0xFF },//343
        { "", 0xFF },//344
        { "", 0xFF },//345
        { "", 0xFF },//346
        { "", 0xFF },//347
        { "", 0xFF },//348
        { "", 0xFF },//349
        { "", 0xFF },//350
        { "", 0xFF },//351
        { "", 0xFF },//352
        { "", 0xFF },//353
        { "", 0xFF },//354
        { "", 0xFF },//355
        { "", 0xFF },//356
        { "", 0xFF },//357
        { "", 0xFF },//358
        { "", 0xFF },//359
        { "", 0xFF },//360
        { "", 0xFF },//361
        { "", 0xFF },//362
        { "", 0xFF },//363
        { "", 0xFF },//364
        { "", 0xFF },//365
        { "", 0xFF },//366
        { "", 0xFF },//367
        { "", 0xFF },//368
        { "", 0xFF },//369
        { "", 0xFF },//370
        { "", 0xFF },//371
        { "", 0xFF },//372
        { "", 0xFF },//373
        { "", 0xFF },//374
        { "", 0xFF },//375
        { "", 0xFF },//376
        { "", 0xFF },//377
        { "", 0xFF },//378
        { "", 0xFF },//379
        { "", 0xFF },//380
        { "", 0xFF },//381
        { "", 0xFF },//382
        { "", 0xFF },//383
        { "", 0xFF },//384
        { "", 0xFF },//385
        { "", 0xFF },//386
        { "", 0xFF },//387
        { "", 0xFF },//388
        { "", 0xFF },//389
        { "", 0xFF },//390
        { "", 0xFF },//391
        { "", 0xFF },//392
        { "", 0xFF },//393
        { "", 0xFF },//394
        { "", 0xFF },//395
        { "", 0xFF },//396
        { "", 0xFF },//397
        { "", 0xFF },//398
        { "", 0xFF },//399
      //400
        { "", 0xFF },//400
        { "", 0xFF },//401
        { "", 0xFF },//402
        { "", 0xFF },//403
        { "", 0xFF },//404
        { "", 0xFF },//405
        { "", 0xFF },//406
        { "", 0xFF },//407
        { "", 0xFF },//408
        { "", 0xFF },//409
        { "", 0xFF },//410
        { "", 0xFF },//411
        { "", 0xFF },//412
        { "", 0xFF },//413
        { "", 0xFF },//414
        { "", 0xFF },//415
        { "", 0xFF },//416
        { "", 0xFF },//417
        { "", 0xFF },//418
        { "", 0xFF },//419
        { "", 0xFF },//420
        { "", 0xFF },//421
        { "", 0xFF },//422
        { "", 0xFF },//423
        { "", 0xFF },//424
        { "", 0xFF },//425
        { "", 0xFF },//426
        { "", 0xFF },//427
        { "", 0xFF },//428
        { "", 0xFF },//429
        { "", 0xFF },//430
        { "", 0xFF },//431
        { "", 0xFF },//432
        { "", 0xFF },//433
        { "", 0xFF },//434
        { "", 0xFF },//435
        { "", 0xFF },//436
        { "", 0xFF },//437
        { "", 0xFF },//438
        { "", 0xFF },//439
        { "", 0xFF },//440
        { "", 0xFF },//441
        { "", 0xFF },//442
        { "", 0xFF },//443
        { "", 0xFF },//444
        { "", 0xFF },//445
        { "", 0xFF },//446
        { "", 0xFF },//447
        { "", 0xFF },//448
        { "", 0xFF },//449
        { "", 0xFF },//450
        { "", 0xFF },//451
        { "", 0xFF },//452
        { "", 0xFF },//453
        { "", 0xFF },//454
        { "", 0xFF },//455
        { "", 0xFF },//456
        { "", 0xFF },//457
        { "", 0xFF },//458
        { "", 0xFF },//459
        { "", 0xFF },//460
        { "", 0xFF },//461
        { "", 0xFF },//462
        { "", 0xFF },//463
        { "", 0xFF },//464
        { "", 0xFF },//465
        { "", 0xFF },//466
        { "", 0xFF },//467
        { "", 0xFF },//468
        { "", 0xFF },//469
        { "", 0xFF },//470
        { "", 0xFF },//471
        { "", 0xFF },//472
        { "", 0xFF },//473
        { "", 0xFF },//474
        { "", 0xFF },//475
        { "", 0xFF },//476
        { "", 0xFF },//477
        { "", 0xFF },//478
        { "", 0xFF },//479
        { "", 0xFF },//480
        { "", 0xFF },//481
        { "", 0xFF },//482
        { "", 0xFF },//483
        { "", 0xFF },//484
        { "", 0xFF },//485
        { "", 0xFF },//486
        { "", 0xFF },//487
        { "", 0xFF },//488
        { "", 0xFF },//489
        { "", 0xFF },//490
        { "", 0xFF },//491
        { "", 0xFF },//492
        { "", 0xFF },//493
        { "", 0xFF },//494
        { "", 0xFF },//495
        { "", 0xFF },//496
        { "", 0xFF },//497
        { "", 0xFF },//498
        { "", 0xFF },//499
      //500
        { "", 0xFF },//500
        { "", 0xFF },//501
        { "", 0xFF },//502
        { "", 0xFF },//503
        { "", 0xFF },//504
        { "", 0xFF },//505
        { "", 0xFF },//506
        { "", 0xFF },//507
        { "FX_ROUTE", 3 },//508
        { "", 0xFF },//509
        { "", 0xFF },//510
        { "", 0xFF },//511
        { "", 0xFF }//512
  };

PARAM_INFO code xfm_lookup[] =
  {
//oscillators
       { "", 0xFF },//0
       { "", 0xFF },//1
       { "", 0xFF },//2
       { "", 0xFF },//3
       { "", 0xFF },//4
       { "", 0xFF },//5
       { "", 0xFF },//6
       { "", 0xFF },//7
       { "", 0xFF },//8
       { "", 0xFF },//9
       { "", 0xFF },//10
       { "", 0xFF },//11
       { "", 0xFF },//12
       { "", 0xFF },//13
       { "", 0xFF },//14
       { "", 0xFF },//15
       { "", 0xFF },//16
       { "", 0xFF },//17
       { "", 0xFF },//18
       { "", 0xFF },//19
       { "", 0xFF },//20
       { "", 0xFF },//21
       { "", 0xFF },//22
       { "", 0xFF },//23
       { "", 0xFF },//24
       { "", 0xFF },//25
       { "", 0xFF },//26
       { "", 0xFF },//27
       { "", 0xFF },//28
       { "", 0xFF },//29
       { "", 0xFF },//30
       { "", 0xFF },//31
       { "", 0xFF },//32
       { "", 0xFF },//33
       { "", 0xFF },//34
       { "", 0xFF },//35
       { "", 0xFF },//36
       { "", 0xFF },//37
       { "", 0xFF },//38
       { "", 0xFF },//39
       { "", 0xFF },//40
       { "", 0xFF },//41
       { "", 0xFF },//42
       { "", 0xFF },//43
       { "", 0xFF },//44
       { "", 0xFF },//45
       { "", 0xFF },//46
       { "", 0xFF },//47
       { "", 0xFF },//48
       { "", 0xFF },//49
       { "", 0xFF },//50
       { "", 0xFF },//51
       { "", 0xFF },//52
       { "", 0xFF },//53
       { "", 0xFF },//54
       { "", 0xFF },//55
       { "", 0xFF },//56
       { "", 0xFF },//57
       { "", 0xFF },//58
       { "", 0xFF },//59
       { "", 0xFF },//60
       { "", 0xFF },//61
       { "", 0xFF },//62
       { "", 0xFF },//63
       { "", 0xFF },//64
       { "", 0xFF },//65
       { "", 0xFF },//66
       { "", 0xFF },//67
       { "", 0xFF },//68
       { "", 0xFF },//69
       { "", 0xFF },//70
       { "", 0xFF },//71
       { "", 0xFF },//72
       { "", 0xFF },//73
       { "", 0xFF },//74
       { "", 0xFF },//75
       { "", 0xFF },//76
       { "", 0xFF },//77
       { "", 0xFF },//78
       { "", 0xFF },//79
       { "", 0xFF },//80
       { "", 0xFF },//81
       { "", 0xFF },//82
       { "", 0xFF },//83
       { "", 0xFF },//84
       { "", 0xFF },//85
       { "", 0xFF },//86
       { "", 0xFF },//87
       { "", 0xFF },//88
       { "", 0xFF },//89
       { "", 0xFF },//90
       { "", 0xFF },//91
       { "", 0xFF },//92
       { "", 0xFF },//93
       { "", 0xFF },//94
       { "", 0xFF },//95
       { "", 0xFF },//96
       { "", 0xFF },//97
       { "", 0xFF },//98
       { "", 0xFF },//99

     //100

       { "", 0xFF },//100
       { "", 0xFF },//101
       { "", 0xFF },//102
       { "", 0xFF },//103
       { "", 0xFF },//104
       { "", 0xFF },//105
       { "", 0xFF },//106
       { "", 0xFF },//107
       { "", 0xFF },//108
       { "", 0xFF },//109
       { "", 0xFF },//110
       { "", 0xFF },//111
       { "", 0xFF },//112
       { "", 0xFF },//113
       { "", 0xFF },//114
       { "", 0xFF },//115
       { "", 0xFF },//116
       { "", 0xFF },//117
       { "", 0xFF },//118
       { "", 0xFF },//119
       { "", 0xFF },//120
       { "", 0xFF },//121
       { "", 0xFF },//122
       { "", 0xFF },//123
       { "", 0xFF },//124
       { "", 0xFF },//125
       { "", 0xFF },//126
       { "", 0xFF },//127
       { "", 0xFF },//128
       { "", 0xFF },//129
       { "", 0xFF },//130
       { "", 0xFF },//131
       { "", 0xFF },//132
       { "", 0xFF },//133
       { "", 0xFF },//134
       { "", 0xFF },//135
       { "", 0xFF },//136
       { "", 0xFF },//137
       { "", 0xFF },//138
       { "", 0xFF },//139
       { "", 0xFF },//140
       { "", 0xFF },//141
       { "", 0xFF },//142
       { "", 0xFF },//143
       { "", 0xFF },//144
       { "", 0xFF },//145
       { "", 0xFF },//146
       { "", 0xFF },//147
       { "", 0xFF },//148
       { "", 0xFF },//149
       { "", 0xFF },//150
       { "", 0xFF },//151
       { "", 0xFF },//152
       { "", 0xFF },//153
       { "", 0xFF },//154
       { "", 0xFF },//155
       { "", 0xFF },//156
       { "", 0xFF },//157
       { "", 0xFF },//158
       { "", 0xFF },//159
       { "", 0xFF },//160
       { "", 0xFF },//161
       { "", 0xFF },//162
       { "", 0xFF },//163
       { "", 0xFF },//164
       { "", 0xFF },//165
       { "", 0xFF },//166
       { "", 0xFF },//167
       { "", 0xFF },//168
       { "", 0xFF },//169
       { "", 0xFF },//170
       { "", 0xFF },//171
       { "", 0xFF },//172
       { "", 0xFF },//173
       { "", 0xFF },//174
       { "", 0xFF },//175
       { "", 0xFF },//176
       { "", 0xFF },//177
       { "", 0xFF },//178
       { "", 0xFF },//179
       { "", 0xFF },//180
       { "", 0xFF },//181
       { "", 0xFF },//182
       { "", 0xFF },//183
       { "", 0xFF },//184
       { "", 0xFF },//185
       { "", 0xFF },//186
       { "", 0xFF },//187
       { "", 0xFF },//188
       { "", 0xFF },//189
       { "", 0xFF },//190
       { "", 0xFF },//191
       { "", 0xFF },//192
       { "", 0xFF },//193
       { "", 0xFF },//194
       { "", 0xFF },//195
       { "", 0xFF },//196
       { "", 0xFF },//197
       { "", 0xFF },//198
       { "", 0xFF },//199
     //200
       { "", 0xFF },//200
       { "", 0xFF },//201
       { "", 0xFF },//202
       { "", 0xFF },//203
       { "", 0xFF },//204
       { "", 0xFF },//205
       { "", 0xFF },//206
       { "", 0xFF },//207
       { "", 0xFF },//208
       { "", 0xFF },//209
       { "", 0xFF },//210
       { "", 0xFF },//211
       { "", 0xFF },//212
       { "", 0xFF },//213
       { "", 0xFF },//214
       { "", 0xFF },//215
       { "", 0xFF },//216
       { "", 0xFF },//217
       { "", 0xFF },//218
       { "", 0xFF },//219
       { "", 0xFF },//220
       { "", 0xFF },//221
       { "", 0xFF },//222
       { "", 0xFF },//223
       { "", 0xFF },//224
       { "", 0xFF },//225
       { "", 0xFF },//226
       { "", 0xFF },//227
       { "", 0xFF },//228
       { "", 0xFF },//229
       { "", 0xFF },//230
       { "", 0xFF },//231
       { "", 0xFF },//232
       { "", 0xFF },//233
       { "", 0xFF },//234
       { "", 0xFF },//235
       { "", 0xFF },//236
       { "", 0xFF },//237
       { "", 0xFF },//238
       { "", 0xFF },//239
       { "", 0xFF },//240
       { "", 0xFF },//241
       { "", 0xFF },//242
       { "", 0xFF },//243
       { "", 0xFF },//244
       { "", 0xFF },//245
       { "", 0xFF },//246
       { "", 0xFF },//247
       { "", 0xFF },//248
       { "", 0xFF },//249
       { "", 0xFF },//250
       { "", 0xFF },//251
       { "", 0xFF },//252
       { "", 0xFF },//253
       { "", 0xFF },//254
       { "", 0xFF },//255
       { "", 0xFF },//256
       { "", 0xFF },//257
       { "", 0xFF },//258
       { "", 0xFF },//259
       { "", 0xFF },//260
       { "", 0xFF },//261
       { "", 0xFF },//262
       { "", 0xFF },//263
       { "", 0xFF },//264
       { "", 0xFF },//265
       { "", 0xFF },//266
       { "", 0xFF },//267
       { "", 0xFF },//268
       { "", 0xFF },//269
       { "", 0xFF },//270
       { "", 0xFF },//271
       { "", 0xFF },//272
       { "", 0xFF },//273
       { "", 0xFF },//274
       { "", 0xFF },//275
       { "", 0xFF },//276
       { "", 0xFF },//277
       { "", 0xFF },//278
       { "", 0xFF },//279
       { "", 0xFF },//280
       { "", 0xFF },//281
       { "", 0xFF },//282
       { "", 0xFF },//283
       { "", 0xFF },//284
       { "", 0xFF },//285
       { "", 0xFF },//286
       { "", 0xFF },//287
       { "", 0xFF },//288
       { "", 0xFF },//289
       { "", 0xFF },//290
       { "", 0xFF },//291
       { "", 0xFF },//292
       { "", 0xFF },//293
       { "", 0xFF },//294
       { "", 0xFF },//295
       { "", 0xFF },//296
       { "", 0xFF },//297
       { "", 0xFF },//298
       { "", 0xFF },//299
     //300
       { "", 0xFF },//300
       { "", 0xFF },//301
       { "", 0xFF },//302
       { "", 0xFF },//303
       { "", 0xFF },//304
       { "", 0xFF },//305
       { "", 0xFF },//306
       { "", 0xFF },//307
       { "", 0xFF },//308
       { "", 0xFF },//309
       { "", 0xFF },//310
       { "", 0xFF },//311
       { "", 0xFF },//312
       { "", 0xFF },//313
       { "", 0xFF },//314
       { "", 0xFF },//315
       { "", 0xFF },//316
       { "", 0xFF },//317
       { "", 0xFF },//318
       { "", 0xFF },//319
       { "", 0xFF },//320
       { "", 0xFF },//321
       { "", 0xFF },//322
       { "", 0xFF },//323
       { "", 0xFF },//324
       { "", 0xFF },//325
       { "", 0xFF },//326
       { "", 0xFF },//327
       { "", 0xFF },//328
       { "", 0xFF },//329
       { "", 0xFF },//330
       { "", 0xFF },//331
       { "", 0xFF },//332
       { "", 0xFF },//333
       { "", 0xFF },//334
       { "", 0xFF },//335
       { "", 0xFF },//336
       { "", 0xFF },//337
       { "", 0xFF },//338
       { "", 0xFF },//339
       { "", 0xFF },//340
       { "", 0xFF },//341
       { "", 0xFF },//342
       { "", 0xFF },//343
       { "", 0xFF },//344
       { "", 0xFF },//345
       { "", 0xFF },//346
       { "", 0xFF },//347
       { "", 0xFF },//348
       { "", 0xFF },//349
       { "", 0xFF },//350
       { "", 0xFF },//351
       { "", 0xFF },//352
       { "", 0xFF },//353
       { "", 0xFF },//354
       { "", 0xFF },//355
       { "", 0xFF },//356
       { "", 0xFF },//357
       { "", 0xFF },//358
       { "", 0xFF },//359
       { "", 0xFF },//360
       { "", 0xFF },//361
       { "", 0xFF },//362
       { "", 0xFF },//363
       { "", 0xFF },//364
       { "", 0xFF },//365
       { "", 0xFF },//366
       { "", 0xFF },//367
       { "", 0xFF },//368
       { "", 0xFF },//369
       { "", 0xFF },//370
       { "", 0xFF },//371
       { "", 0xFF },//372
       { "", 0xFF },//373
       { "", 0xFF },//374
       { "", 0xFF },//375
       { "", 0xFF },//376
       { "", 0xFF },//377
       { "", 0xFF },//378
       { "", 0xFF },//379
       { "", 0xFF },//380
       { "", 0xFF },//381
       { "", 0xFF },//382
       { "", 0xFF },//383
       { "", 0xFF },//384
       { "", 0xFF },//385
       { "", 0xFF },//386
       { "", 0xFF },//387
       { "", 0xFF },//388
       { "", 0xFF },//389
       { "", 0xFF },//390
       { "", 0xFF },//391
       { "", 0xFF },//392
       { "", 0xFF },//393
       { "", 0xFF },//394
       { "", 0xFF },//395
       { "", 0xFF },//396
       { "", 0xFF },//397
       { "", 0xFF },//398
       { "", 0xFF },//399
     //400
       { "", 0xFF },//400
       { "", 0xFF },//401
       { "", 0xFF },//402
       { "", 0xFF },//403
       { "", 0xFF },//404
       { "", 0xFF },//405
       { "", 0xFF },//406
       { "", 0xFF },//407
       { "", 0xFF },//408
       { "", 0xFF },//409
       { "", 0xFF },//410
       { "", 0xFF },//411
       { "", 0xFF },//412
       { "", 0xFF },//413
       { "", 0xFF },//414
       { "", 0xFF },//415
       { "", 0xFF },//416
       { "", 0xFF },//417
       { "", 0xFF },//418
       { "", 0xFF },//419
       { "", 0xFF },//420
       { "", 0xFF },//421
       { "", 0xFF },//422
       { "", 0xFF },//423
       { "", 0xFF },//424
       { "", 0xFF },//425
       { "", 0xFF },//426
       { "", 0xFF },//427
       { "", 0xFF },//428
       { "", 0xFF },//429
       { "", 0xFF },//430
       { "", 0xFF },//431
       { "", 0xFF },//432
       { "", 0xFF },//433
       { "", 0xFF },//434
       { "", 0xFF },//435
       { "", 0xFF },//436
       { "", 0xFF },//437
       { "", 0xFF },//438
       { "", 0xFF },//439
       { "", 0xFF },//440
       { "", 0xFF },//441
       { "", 0xFF },//442
       { "", 0xFF },//443
       { "", 0xFF },//444
       { "", 0xFF },//445
       { "", 0xFF },//446
       { "", 0xFF },//447
       { "", 0xFF },//448
       { "", 0xFF },//449
       { "", 0xFF },//450
       { "", 0xFF },//451
       { "", 0xFF },//452
       { "", 0xFF },//453
       { "", 0xFF },//454
       { "", 0xFF },//455
       { "", 0xFF },//456
       { "", 0xFF },//457
       { "", 0xFF },//458
       { "", 0xFF },//459
       { "", 0xFF },//460
       { "", 0xFF },//461
       { "", 0xFF },//462
       { "", 0xFF },//463
       { "", 0xFF },//464
       { "", 0xFF },//465
       { "", 0xFF },//466
       { "", 0xFF },//467
       { "", 0xFF },//468
       { "", 0xFF },//469
       { "", 0xFF },//470
       { "", 0xFF },//471
       { "", 0xFF },//472
       { "", 0xFF },//473
       { "", 0xFF },//474
       { "", 0xFF },//475
       { "", 0xFF },//476
       { "", 0xFF },//477
       { "", 0xFF },//478
       { "", 0xFF },//479
       { "", 0xFF },//480
       { "", 0xFF },//481
       { "", 0xFF },//482
       { "", 0xFF },//483
       { "", 0xFF },//484
       { "", 0xFF },//485
       { "", 0xFF },//486
       { "", 0xFF },//487
       { "", 0xFF },//488
       { "", 0xFF },//489
       { "", 0xFF },//490
       { "", 0xFF },//491
       { "", 0xFF },//492
       { "", 0xFF },//493
       { "", 0xFF },//494
       { "", 0xFF },//495
       { "", 0xFF },//496
       { "", 0xFF },//497
       { "", 0xFF },//498
       { "", 0xFF },//499
     //500
       { "", 0xFF },//500
       { "", 0xFF },//501
       { "", 0xFF },//502
       { "", 0xFF },//503
       { "", 0xFF },//504
       { "", 0xFF },//505
       { "", 0xFF },//506
       { "", 0xFF },//507
       { "", 0xFF },//508
       { "", 0xFF },//509
       { "", 0xFF },//510
       { "", 0xFF },//511
       { "", 0xFF }//512
  };

#endif /* INC_SYNTH_INTERFACE_VALUE_LOOKUP_H_ */
