//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB3_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void
enter_DefaultMode_from_RESET (void)
{
  // $[Config Calls]
  // Save the SFRPAGE
  uint8_t SFRPAGE_save = SFRPAGE;
  WDT_0_enter_DefaultMode_from_RESET ();
  PORTS_0_enter_DefaultMode_from_RESET ();
  PORTS_1_enter_DefaultMode_from_RESET ();
  PORTS_2_enter_DefaultMode_from_RESET ();
  PBCFG_0_enter_DefaultMode_from_RESET ();
  LFOSC_0_enter_DefaultMode_from_RESET ();
  CIP51_0_enter_DefaultMode_from_RESET ();
  RSTSRC_0_enter_DefaultMode_from_RESET ();
  CLOCK_0_enter_DefaultMode_from_RESET ();
  TIMER01_0_enter_DefaultMode_from_RESET ();
  TIMER16_2_enter_DefaultMode_from_RESET ();
  TIMER_SETUP_0_enter_DefaultMode_from_RESET ();
  PCA_0_enter_DefaultMode_from_RESET ();
  PCACH_0_enter_DefaultMode_from_RESET ();
  UART_0_enter_DefaultMode_from_RESET ();
  INTERRUPT_0_enter_DefaultMode_from_RESET ();
  // Restore the SFRPAGE
  SFRPAGE = SFRPAGE_save;
  // [Config Calls]$

}

extern void
WDT_0_enter_DefaultMode_from_RESET (void)
{
  // $[Watchdog Timer Init Variable Declarations]
  uint32_t i;
  bool ea;
  // [Watchdog Timer Init Variable Declarations]$

  // $[WDTCN - Watchdog Timer Control]
  // Deprecated
  // [WDTCN - Watchdog Timer Control]$

  // $[WDTCN_2 - Watchdog Timer Control]
  SFRPAGE = 0x00;

  // Feed WDT timer before disabling (Erratum WDT_E102)
  WDTCN = 0xA5;

  // Add 2 LFO cycle delay before disabling WDT (Erratum WDT_E102)
  for (i = 0; i < (2 * 3062500UL) / (80000 * 3); i++)
    {
      NOP ();
    }

  // Disable WDT before changing interval
  ea = IE_EA;
  IE_EA = 0;
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  IE_EA = ea;

  // Delay 2 LFO cycles to ensure WDT is completely disabled
  for (i = 0; i < (2 * 3062500UL) / (80000 * 3); i++)
    {
      NOP ();
    }

  // Change WDT interval
  WDTCN = 5;

  // Start WDT
  WDTCN = 0xA5;

  // [WDTCN_2 - Watchdog Timer Control]$

}

extern void
PORTS_0_enter_DefaultMode_from_RESET (void)
{
  // $[P0 - Port 0 Pin Latch]
  /***********************************************************************
   - P0.0 is high. Set P0.0 to drive or float high
   - P0.1 is low. Set P0.1 to drive low
   - P0.2 is low. Set P0.2 to drive low
   - P0.3 is low. Set P0.3 to drive low
   - P0.4 is high. Set P0.4 to drive or float high
   - P0.5 is high. Set P0.5 to drive or float high
   - P0.6 is high. Set P0.6 to drive or float high
   - P0.7 is low. Set P0.7 to drive low
   ***********************************************************************/
  P0 = P0_B0__HIGH | P0_B1__LOW | P0_B2__LOW | P0_B3__LOW | P0_B4__HIGH
      | P0_B5__HIGH | P0_B6__HIGH | P0_B7__LOW;
  // [P0 - Port 0 Pin Latch]$

  // $[P0MDOUT - Port 0 Output Mode]
  /***********************************************************************
   - P0.0 output is open-drain
   - P0.1 output is push-pull
   - P0.2 output is push-pull
   - P0.3 output is push-pull
   - P0.4 output is push-pull
   - P0.5 output is open-drain
   - P0.6 output is open-drain
   - P0.7 output is open-drain
   ***********************************************************************/
  P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__PUSH_PULL
      | P0MDOUT_B2__PUSH_PULL | P0MDOUT_B3__PUSH_PULL | P0MDOUT_B4__PUSH_PULL
      | P0MDOUT_B5__OPEN_DRAIN | P0MDOUT_B6__OPEN_DRAIN
      | P0MDOUT_B7__OPEN_DRAIN;
  // [P0MDOUT - Port 0 Output Mode]$

  // $[P0MDIN - Port 0 Input Mode]
  // [P0MDIN - Port 0 Input Mode]$

  // $[P0SKIP - Port 0 Skip]
  /***********************************************************************
   - P0.0 pin is skipped by the crossbar
   - P0.1 pin is not skipped by the crossbar
   - P0.2 pin is not skipped by the crossbar
   - P0.3 pin is skipped by the crossbar
   - P0.4 pin is not skipped by the crossbar
   - P0.5 pin is not skipped by the crossbar
   - P0.6 pin is skipped by the crossbar
   - P0.7 pin is skipped by the crossbar
   ***********************************************************************/
  P0SKIP = P0SKIP_B0__SKIPPED | P0SKIP_B1__NOT_SKIPPED | P0SKIP_B2__NOT_SKIPPED
      | P0SKIP_B3__SKIPPED | P0SKIP_B4__NOT_SKIPPED | P0SKIP_B5__NOT_SKIPPED
      | P0SKIP_B6__SKIPPED | P0SKIP_B7__SKIPPED;
  // [P0SKIP - Port 0 Skip]$

  // $[P0MASK - Port 0 Mask]
  // [P0MASK - Port 0 Mask]$

  // $[P0MAT - Port 0 Match]
  // [P0MAT - Port 0 Match]$

}

extern void
PORTS_2_enter_DefaultMode_from_RESET (void)
{
  // $[P2 - Port 2 Pin Latch]
  /***********************************************************************
   - P2.0 is low. Set P2.0 to drive low
   - P2.1 is low. Set P2.1 to drive low
   - P2.2 is low. Set P2.2 to drive low
   - P2.3 is low. Set P2.3 to drive low
   ***********************************************************************/
  P2 = P2_B0__LOW | P2_B1__LOW | P2_B2__LOW | P2_B3__LOW;
  // [P2 - Port 2 Pin Latch]$

  // $[P2MDOUT - Port 2 Output Mode]
  /***********************************************************************
   - P2.0 output is push-pull
   - P2.1 output is push-pull
   - P2.2 output is push-pull
   - P2.3 output is push-pull
   ***********************************************************************/
  P2MDOUT = P2MDOUT_B0__PUSH_PULL | P2MDOUT_B1__PUSH_PULL
      | P2MDOUT_B2__PUSH_PULL | P2MDOUT_B3__PUSH_PULL;
  // [P2MDOUT - Port 2 Output Mode]$

  // $[P2MDIN - Port 2 Input Mode]
  // [P2MDIN - Port 2 Input Mode]$

  // $[P2SKIP - Port 2 Skip]
  // [P2SKIP - Port 2 Skip]$

  // $[P2MASK - Port 2 Mask]
  // [P2MASK - Port 2 Mask]$

  // $[P2MAT - Port 2 Match]
  // [P2MAT - Port 2 Match]$

}

extern void
PBCFG_0_enter_DefaultMode_from_RESET (void)
{
  // $[XBR2 - Port I/O Crossbar 2]
  /***********************************************************************
   - Weak Pullups disabled
   - Crossbar enabled
   - UART1 I/O unavailable at Port pin
   - UART1 RTS1 unavailable at Port pin
   - UART1 CTS1 unavailable at Port pin
   ***********************************************************************/
  XBR2 = XBR2_WEAKPUD__PULL_UPS_DISABLED | XBR2_XBARE__ENABLED
      | XBR2_URT1E__DISABLED | XBR2_URT1RTSE__DISABLED
      | XBR2_URT1CTSE__DISABLED;
  // [XBR2 - Port I/O Crossbar 2]$

  // $[PRTDRV - Port Drive Strength]
  // [PRTDRV - Port Drive Strength]$

  // $[XBR0 - Port I/O Crossbar 0]
  /***********************************************************************
   - UART0 TX0, RX0 routed to Port pins P0.4 and P0.5
   - SPI I/O unavailable at Port pins
   - SMBus 0 I/O unavailable at Port pins
   - CP0 unavailable at Port pin
   - Asynchronous CP0 unavailable at Port pin
   - CP1 unavailable at Port pin
   - Asynchronous CP1 unavailable at Port pin
   - SYSCLK unavailable at Port pin
   ***********************************************************************/
  XBR0 = XBR0_URT0E__ENABLED | XBR0_SPI0E__DISABLED | XBR0_SMB0E__DISABLED
      | XBR0_CP0E__DISABLED | XBR0_CP0AE__DISABLED | XBR0_CP1E__DISABLED
      | XBR0_CP1AE__DISABLED | XBR0_SYSCKE__DISABLED;
  // [XBR0 - Port I/O Crossbar 0]$

  // $[XBR1 - Port I/O Crossbar 1]
  /***********************************************************************
   - CEX0, CEX1, CEX2, CEX3, CEX4, CEX5 routed to Port pins
   - ECI unavailable at Port pin
   - T0 unavailable at Port pin
   - T1 unavailable at Port pin
   - T2 unavailable at Port pin
   ***********************************************************************/
  XBR1 = XBR1_PCA0ME__CEX0_TO_CEX5 | XBR1_ECIE__DISABLED | XBR1_T0E__DISABLED
      | XBR1_T1E__DISABLED | XBR1_T2E__DISABLED;
  // [XBR1 - Port I/O Crossbar 1]$

}

extern void
TIMER_SETUP_0_enter_DefaultMode_from_RESET (void)
{
  // $[CKCON0 - Clock Control 0]
  /***********************************************************************
   - System clock divided by 4
   - Counter/Timer 0 uses the clock defined by the prescale field, SCA
   - Timer 2 high byte uses the clock defined by T2XCLK in TMR2CN0
   - Timer 2 low byte uses the clock defined by T2XCLK in TMR2CN0
   - Timer 3 high byte uses the clock defined by T3XCLK in TMR3CN0
   - Timer 3 low byte uses the clock defined by T3XCLK in TMR3CN0
   - Timer 1 uses the system clock
   ***********************************************************************/
  CKCON0 = CKCON0_SCA__SYSCLK_DIV_4 | CKCON0_T0M__PRESCALE
      | CKCON0_T2MH__EXTERNAL_CLOCK | CKCON0_T2ML__EXTERNAL_CLOCK
      | CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
      | CKCON0_T1M__SYSCLK;
  // [CKCON0 - Clock Control 0]$

  // $[CKCON1 - Clock Control 1]
  // [CKCON1 - Clock Control 1]$

  // $[TMOD - Timer 0/1 Mode]
  /***********************************************************************
   - Mode 0, 13-bit Counter/Timer
   - Mode 2, 8-bit Counter/Timer with Auto-Reload
   - Timer Mode
   - Timer 0 enabled when TR0 = 1 irrespective of INT0 logic level
   - Timer Mode
   - Timer 1 enabled when TR1 = 1 irrespective of INT1 logic level
   ***********************************************************************/
  TMOD = TMOD_T0M__MODE0 | TMOD_T1M__MODE2 | TMOD_CT0__TIMER
      | TMOD_GATE0__DISABLED | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
  // [TMOD - Timer 0/1 Mode]$

  // $[TCON - Timer 0/1 Control]
  /***********************************************************************
   - Start Timer 1 running
   ***********************************************************************/
  TCON |= TCON_TR1__RUN;
  // [TCON - Timer 0/1 Control]$

}

extern void
UART_0_enter_DefaultMode_from_RESET (void)
{
  // $[SCON0 - UART0 Serial Port Control]
  // [SCON0 - UART0 Serial Port Control]$

}

extern void
TIMER16_2_enter_DefaultMode_from_RESET (void)
{
  // $[Timer Initialization]
  // Save Timer Configuration
  uint8_t TMR2CN0_TR2_save;
  TMR2CN0_TR2_save = TMR2CN0 & TMR2CN0_TR2__BMASK;
  // Stop Timer
  TMR2CN0 &= ~(TMR2CN0_TR2__BMASK);
  // [Timer Initialization]$

  // $[TMR2CN1 - Timer 2 Control 1]
  // [TMR2CN1 - Timer 2 Control 1]$

  // $[TMR2CN0 - Timer 2 Control]
  // [TMR2CN0 - Timer 2 Control]$

  // $[TMR2H - Timer 2 High Byte]
  // [TMR2H - Timer 2 High Byte]$

  // $[TMR2L - Timer 2 Low Byte]
  // [TMR2L - Timer 2 Low Byte]$

  // $[TMR2RLH - Timer 2 Reload High Byte]
  /***********************************************************************
   - Timer 2 Reload High Byte = 0xF0
   ***********************************************************************/
  TMR2RLH = (0xF0 << TMR2RLH_TMR2RLH__SHIFT);
  // [TMR2RLH - Timer 2 Reload High Byte]$

  // $[TMR2RLL - Timer 2 Reload Low Byte]
  /***********************************************************************
   - Timer 2 Reload Low Byte = 0x0D
   ***********************************************************************/
  TMR2RLL = (0x0D << TMR2RLL_TMR2RLL__SHIFT);
  // [TMR2RLL - Timer 2 Reload Low Byte]$

  // $[TMR2CN0]
  /***********************************************************************
   - Start Timer 2 running
   ***********************************************************************/
  TMR2CN0 |= TMR2CN0_TR2__RUN;
  // [TMR2CN0]$

  // $[Timer Restoration]
  // Restore Timer Configuration
  TMR2CN0 |= TMR2CN0_TR2_save;
  // [Timer Restoration]$

}

extern void
INTERRUPT_0_enter_DefaultMode_from_RESET (void)
{
  // $[EIE1 - Extended Interrupt Enable 1]
  // [EIE1 - Extended Interrupt Enable 1]$

  // $[EIE2 - Extended Interrupt Enable 2]
  // [EIE2 - Extended Interrupt Enable 2]$

  // $[EIP1H - Extended Interrupt Priority 1 High]
  // [EIP1H - Extended Interrupt Priority 1 High]$

  // $[EIP1 - Extended Interrupt Priority 1 Low]
  // [EIP1 - Extended Interrupt Priority 1 Low]$

  // $[EIP2 - Extended Interrupt Priority 2]
  // [EIP2 - Extended Interrupt Priority 2]$

  // $[EIP2H - Extended Interrupt Priority 2 High]
  // [EIP2H - Extended Interrupt Priority 2 High]$

  // $[IE - Interrupt Enable]
  /***********************************************************************
   - Enable each interrupt according to its individual mask setting
   - Disable external interrupt 0
   - Disable external interrupt 1
   - Disable all SPI0 interrupts
   - Disable all Timer 0 interrupt
   - Disable all Timer 1 interrupt
   - Enable interrupt requests generated by the TF2L or TF2H flags
   - Enable UART0 interrupt
   ***********************************************************************/
  IE = IE_EA__ENABLED | IE_EX0__DISABLED | IE_EX1__DISABLED | IE_ESPI0__DISABLED
      | IE_ET0__DISABLED | IE_ET1__DISABLED | IE_ET2__ENABLED | IE_ES0__ENABLED;
  // [IE - Interrupt Enable]$

  // $[IP - Interrupt Priority]
  // [IP - Interrupt Priority]$

  // $[IPH - Interrupt Priority High]
  // [IPH - Interrupt Priority High]$

}

extern void
CIP51_0_enter_DefaultMode_from_RESET (void)
{
  // $[PFE0CN - Prefetch Engine Control]
  /***********************************************************************
   - SYSCLK < 50 MHz
   ***********************************************************************/
  SFRPAGE = 0x10;
  PFE0CN = PFE0CN_FLRT__SYSCLK_BELOW_50_MHZ;
  // [PFE0CN - Prefetch Engine Control]$

}

extern void
CLOCK_0_enter_DefaultMode_from_RESET (void)
{
  // $[HFOSC1 Setup]
  // Ensure SYSCLK is > 24 MHz before switching to HFOSC1
  CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_1;
  while ((CLKSEL & CLKSEL_DIVRDY__BMASK) == CLKSEL_DIVRDY__NOT_READY)
    ;
  // [HFOSC1 Setup]$

  // $[CLKSEL - Clock Select]
  /***********************************************************************
   - Clock derived from the Internal High Frequency Oscillator 1
   - SYSCLK is equal to selected clock source divided by 1
   ***********************************************************************/
  CLKSEL = CLKSEL_CLKSL__HFOSC1 | CLKSEL_CLKDIV__SYSCLK_DIV_1;
  while ((CLKSEL & CLKSEL_DIVRDY__BMASK) == CLKSEL_DIVRDY__NOT_READY)
    ;
  // [CLKSEL - Clock Select]$

}

extern void
TIMER01_0_enter_DefaultMode_from_RESET (void)
{
  // $[Timer Initialization]
  //Save Timer Configuration
  uint8_t TCON_save;
  TCON_save = TCON;
  //Stop Timers
  TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;

  // [Timer Initialization]$

  // $[TH0 - Timer 0 High Byte]
  // [TH0 - Timer 0 High Byte]$

  // $[TL0 - Timer 0 Low Byte]
  // [TL0 - Timer 0 Low Byte]$

  // $[TH1 - Timer 1 High Byte]
  /***********************************************************************
   - Timer 1 High Byte = 0xCF
   ***********************************************************************/
  TH1 = (0xCF << TH1_TH1__SHIFT);
  // [TH1 - Timer 1 High Byte]$

  // $[TL1 - Timer 1 Low Byte]
  // [TL1 - Timer 1 Low Byte]$

  // $[Timer Restoration]
  //Restore Timer Configuration
  TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);

  // [Timer Restoration]$

}

extern void
PCA_0_enter_DefaultMode_from_RESET (void)
{

  // $[PCA Off]
  PCA0CN0_CR = PCA0CN0_CR__STOP;
  // [PCA Off]$

  // $[PCA0MD - PCA Mode]
  // [PCA0MD - PCA Mode]$

  // $[PCA0CENT - PCA Center Alignment Enable]
  // [PCA0CENT - PCA Center Alignment Enable]$

  // $[PCA0CLR - PCA Comparator Clear Control]
  // [PCA0CLR - PCA Comparator Clear Control]$

  // $[PCA0L - PCA Counter/Timer Low Byte]
  // [PCA0L - PCA Counter/Timer Low Byte]$

  // $[PCA0H - PCA Counter/Timer High Byte]
  // [PCA0H - PCA Counter/Timer High Byte]$

  // $[PCA0POL - PCA Output Polarity]
  // [PCA0POL - PCA Output Polarity]$

  // $[PCA0PWM - PCA PWM Configuration]
  // [PCA0PWM - PCA PWM Configuration]$

  // $[PCA On]
  PCA0CN0_CR = PCA0CN0_CR__RUN;
  // [PCA On]$

}

extern void
LFOSC_0_enter_DefaultMode_from_RESET (void)
{

  // $[LFO0CN - Low Frequency Oscillator Control]
  /***********************************************************************
   - Internal L-F Oscillator Enabled
   ***********************************************************************/
  LFO0CN |= LFO0CN_OSCLEN__ENABLED;
  // [LFO0CN - Low Frequency Oscillator Control]$

  // $[Wait for LFOSC Ready]
  while ((LFO0CN & LFO0CN_OSCLRDY__BMASK) != LFO0CN_OSCLRDY__SET)
    ;
  // [Wait for LFOSC Ready]$

}

extern void
PCACH_0_enter_DefaultMode_from_RESET (void)
{

  // $[PCA0 Settings Save]
  // Select Capture/Compare register)
  PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
  // [PCA0 Settings Save]$

  // $[PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]
  // [PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]$

  // $[PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]
  // [PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]$

  // $[PCA0CPH0 - PCA Channel 0 Capture Module High Byte]
  PCA0CPH0 = 0x00;
  // [PCA0CPH0 - PCA Channel 0 Capture Module High Byte]$

  // $[Auto-reload]
  // [Auto-reload]$

  // $[PCA0 Settings Restore]
  // [PCA0 Settings Restore]$

}

extern void
PCACH_1_enter_DefaultMode_from_RESET (void)
{

  // $[PCA0 Settings Save]
  // Select Capture/Compare register)
  PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
  // [PCA0 Settings Save]$

  // $[PCA0CPM1 - PCA Channel 1 Capture/Compare Mode]
  /***********************************************************************
   - Disable negative edge capture
   - Disable CCF1 interrupts
   - Disable match function
   - 8 to 11-bit PWM selected
   - Disable positive edge capture
   - Enable comparator function
   - Enable PWM function
   - Disable toggle function
   ***********************************************************************/
  PCA0CPM1 = PCA0CPM1_CAPN__DISABLED | PCA0CPM1_ECCF__DISABLED
      | PCA0CPM1_MAT__DISABLED | PCA0CPM1_PWM16__8_BIT | PCA0CPM1_CAPP__DISABLED
      | PCA0CPM1_ECOM__ENABLED | PCA0CPM1_PWM__ENABLED | PCA0CPM1_TOG__DISABLED;
  // [PCA0CPM1 - PCA Channel 1 Capture/Compare Mode]$

  // $[PCA0CPL1 - PCA Channel 1 Capture Module Low Byte]
  // [PCA0CPL1 - PCA Channel 1 Capture Module Low Byte]$

  // $[PCA0CPH1 - PCA Channel 1 Capture Module High Byte]
  PCA0CPH1 = 0x00;
  // [PCA0CPH1 - PCA Channel 1 Capture Module High Byte]$

  // $[Auto-reload]
  // [Auto-reload]$

  // $[PCA0 Settings Restore]
  // [PCA0 Settings Restore]$

}

extern void
PCACH_2_enter_DefaultMode_from_RESET (void)
{

  // $[PCA0 Settings Save]
  // Select Capture/Compare register)
  PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
  // [PCA0 Settings Save]$

  // $[PCA0CPM2 - PCA Channel 2 Capture/Compare Mode]
  /***********************************************************************
   - Disable negative edge capture
   - Disable CCF2 interrupts
   - Disable match function
   - 8 to 11-bit PWM selected
   - Disable positive edge capture
   - Enable comparator function
   - Enable PWM function
   - Disable toggle function
   ***********************************************************************/
  PCA0CPM2 = PCA0CPM2_CAPN__DISABLED | PCA0CPM2_ECCF__DISABLED
      | PCA0CPM2_MAT__DISABLED | PCA0CPM2_PWM16__8_BIT | PCA0CPM2_CAPP__DISABLED
      | PCA0CPM2_ECOM__ENABLED | PCA0CPM2_PWM__ENABLED | PCA0CPM2_TOG__DISABLED;
  // [PCA0CPM2 - PCA Channel 2 Capture/Compare Mode]$

  // $[PCA0CPL2 - PCA Channel 2 Capture Module Low Byte]
  // [PCA0CPL2 - PCA Channel 2 Capture Module Low Byte]$

  // $[PCA0CPH2 - PCA Channel 2 Capture Module High Byte]
  PCA0CPH2 = 0x00;
  // [PCA0CPH2 - PCA Channel 2 Capture Module High Byte]$

  // $[Auto-reload]
  // [Auto-reload]$

  // $[PCA0 Settings Restore]
  // [PCA0 Settings Restore]$

}

extern void
PCACH_3_enter_DefaultMode_from_RESET (void)
{

  // $[PCA0 Settings Save]
  // Select Capture/Compare register)
  PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
  // [PCA0 Settings Save]$

  // $[PCA0CPM3 - PCA Channel 3 Capture/Compare Mode]
  /***********************************************************************
   - Disable negative edge capture
   - Disable CCF3 interrupts
   - Disable match function
   - 8 to 11-bit PWM selected
   - Disable positive edge capture
   - Enable comparator function
   - Enable PWM function
   - Disable toggle function
   ***********************************************************************/
  PCA0CPM3 = PCA0CPM3_CAPN__DISABLED | PCA0CPM3_ECCF__DISABLED
      | PCA0CPM3_MAT__DISABLED | PCA0CPM3_PWM16__8_BIT | PCA0CPM3_CAPP__DISABLED
      | PCA0CPM3_ECOM__ENABLED | PCA0CPM3_PWM__ENABLED | PCA0CPM3_TOG__DISABLED;
  // [PCA0CPM3 - PCA Channel 3 Capture/Compare Mode]$

  // $[PCA0CPL3 - PCA Channel 3 Capture Module Low Byte]
  // [PCA0CPL3 - PCA Channel 3 Capture Module Low Byte]$

  // $[PCA0CPH3 - PCA Channel 3 Capture Module High Byte]
  PCA0CPH3 = 0x00;
  // [PCA0CPH3 - PCA Channel 3 Capture Module High Byte]$

  // $[Auto-reload]
  // [Auto-reload]$

  // $[PCA0 Settings Restore]
  // [PCA0 Settings Restore]$

}

extern void
PORTS_1_enter_DefaultMode_from_RESET (void)
{
  // $[P1 - Port 1 Pin Latch]
  // [P1 - Port 1 Pin Latch]$

  // $[P1MDOUT - Port 1 Output Mode]
  // [P1MDOUT - Port 1 Output Mode]$

  // $[P1MDIN - Port 1 Input Mode]
  // [P1MDIN - Port 1 Input Mode]$

  // $[P1SKIP - Port 1 Skip]
  /***********************************************************************
   - P1.0 pin is skipped by the crossbar
   - P1.1 pin is skipped by the crossbar
   - P1.2 pin is skipped by the crossbar
   - P1.3 pin is skipped by the crossbar
   - P1.4 pin is skipped by the crossbar
   - P1.5 pin is skipped by the crossbar
   - P1.6 pin is skipped by the crossbar
   ***********************************************************************/
  P1SKIP = P1SKIP_B0__SKIPPED | P1SKIP_B1__SKIPPED | P1SKIP_B2__SKIPPED
      | P1SKIP_B3__SKIPPED | P1SKIP_B4__SKIPPED | P1SKIP_B5__SKIPPED
      | P1SKIP_B6__SKIPPED;
  // [P1SKIP - Port 1 Skip]$

  // $[P1MASK - Port 1 Mask]
  // [P1MASK - Port 1 Mask]$

  // $[P1MAT - Port 1 Match]
  // [P1MAT - Port 1 Match]$

}

extern void
RSTSRC_0_enter_DefaultMode_from_RESET (void)
{
  // $[RSTSRC - Reset Source]
  /***********************************************************************
   - A power-on or supply monitor reset occurred
   - A missing clock detector reset occurred
   - A Comparator 0 reset did not occur
   ***********************************************************************/
  SFRPAGE = 0x00;
  RSTSRC = RSTSRC_PORSF__SET | RSTSRC_MCDRSF__SET | RSTSRC_C0RSEF__NOT_SET;
  // [RSTSRC - Reset Source]$

}

