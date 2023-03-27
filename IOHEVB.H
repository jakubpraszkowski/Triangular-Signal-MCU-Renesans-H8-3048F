/*			- IOH83048.H -					*/
/*									*/
/*	Version: 1.00 [IEVH]						*/
/*									*/
/*	Declarations of Special Function Registers, Non Maskable	*/
/*	Interrupt Vectors and Control Registers for H8/3048.		*/
/*									*/
/*	(c) Copyright IAR Systems 1996, 1997				*/
/*									*/
/*      Revision of this file:  $Revision: 1.4 $                        */
/*									*/

#ifndef _IOH83048_INCLUDED
#define _IOH83048_INCLUDED

#if (__TID__ & 0x00F0) >> 4 != 0
#error IOH83048.H header file requires compiler option: -v0
#endif

#ifdef __IAR_SYSTEMS_ICC
#define ICC_UNSIGN_CHAR		*(unsigned char *)
#define ICC_UNSIGN_SHORT	*(unsigned short *)
#define ICC_UNSIGN_LONG		*(unsigned long *)
#else
#define ICC_UNSIGN_CHAR
#define ICC_UNSIGN_SHORT
#define ICC_UNSIGN_LONG
#endif


/*
	H8/3048 Special Function Registers
*/

/*			4 DMA channels
			--------------

*/

#define DMAC_MAR0AR	(ICC_UNSIGN_CHAR	( 0xffffff20 ))
#define DMAC_MAR0AE	(ICC_UNSIGN_CHAR	( 0xffffff21 ))
#define DMAC_MAR0AH	(ICC_UNSIGN_CHAR	( 0xffffff22 ))
#define DMAC_MAR0AL	(ICC_UNSIGN_CHAR	( 0xffffff23 ))
#define DMAC_ETCR0AH	(ICC_UNSIGN_CHAR	( 0xffffff24 ))
#define DMAC_ETCR0AL	(ICC_UNSIGN_CHAR	( 0xffffff25 ))
#define DMAC_ETCR0A     (ICC_UNSIGN_SHORT       ( 0xffffff24 ))
#define DMAC_IOAR0A	(ICC_UNSIGN_CHAR	( 0xffffff26 ))
#define DMAC_DTCR0A	(ICC_UNSIGN_CHAR	( 0xffffff27 ))
#define DMAC_MAR0AW	(ICC_UNSIGN_SHORT	( 0xffffff22 ))
#define DMAC_MAR0A	(ICC_UNSIGN_LONG	( 0xffffff20 ))

#define DMAC_MAR0BR	(ICC_UNSIGN_CHAR	( 0xffffff28 ))
#define DMAC_MAR0BE	(ICC_UNSIGN_CHAR	( 0xffffff29 ))
#define DMAC_MAR0BH	(ICC_UNSIGN_CHAR	( 0xffffff2A ))
#define DMAC_MAR0BL	(ICC_UNSIGN_CHAR	( 0xffffff2B ))
#define DMAC_ETCR0BH	(ICC_UNSIGN_CHAR	( 0xffffff2C ))
#define DMAC_ETCR0BL	(ICC_UNSIGN_CHAR	( 0xffffff2D ))
#define DMAC_ETCR0B     (ICC_UNSIGN_SHORT       ( 0xffffff2C ))
#define DMAC_IOAR0B	(ICC_UNSIGN_CHAR	( 0xffffff2E ))
#define DMAC_DTCR0B	(ICC_UNSIGN_CHAR	( 0xffffff2F ))
#define DMAC_MAR0BW	(ICC_UNSIGN_SHORT	( 0xffffff2A ))
#define DMAC_MAR0B	(ICC_UNSIGN_LONG	( 0xffffff28 ))

#define DMAC_MAR1AR	(ICC_UNSIGN_CHAR	( 0xffffff30 ))
#define DMAC_MAR1AE	(ICC_UNSIGN_CHAR	( 0xffffff31 ))
#define DMAC_MAR1AH	(ICC_UNSIGN_CHAR	( 0xffffff32 ))
#define DMAC_MAR1AL	(ICC_UNSIGN_CHAR	( 0xffffff33 ))
#define DMAC_ETCR1AH	(ICC_UNSIGN_CHAR	( 0xffffff34 ))
#define DMAC_ETCR1AL	(ICC_UNSIGN_CHAR	( 0xffffff35 ))
#define DMAC_ETCR1A     (ICC_UNSIGN_SHORT       ( 0xffffff34 ))
#define DMAC_IOAR1A	(ICC_UNSIGN_CHAR	( 0xffffff36 ))
#define DMAC_DTCR1A	(ICC_UNSIGN_CHAR	( 0xffffff37 ))
#define DMAC_MAR1AW	(ICC_UNSIGN_SHORT	( 0xffffff32 ))
#define DMAC_MAR1A	(ICC_UNSIGN_LONG	( 0xffffff30 ))

#define DMAC_MAR1BR	(ICC_UNSIGN_CHAR	( 0xffffff38 ))
#define DMAC_MAR1BE	(ICC_UNSIGN_CHAR	( 0xffffff39 ))
#define DMAC_MAR1BH	(ICC_UNSIGN_CHAR	( 0xffffff3A ))
#define DMAC_MAR1BL	(ICC_UNSIGN_CHAR	( 0xffffff3B ))
#define DMAC_ETCR1BH	(ICC_UNSIGN_CHAR	( 0xffffff3C ))
#define DMAC_ETCR1BL	(ICC_UNSIGN_CHAR	( 0xffffff3D ))
#define DMAC_ETCR1B     (ICC_UNSIGN_SHORT       ( 0xffffff3C ))
#define DMAC_IOAR1B	(ICC_UNSIGN_CHAR	( 0xffffff3E ))
#define DMAC_DTCR1B	(ICC_UNSIGN_CHAR	( 0xffffff3F ))
#define DMAC_MAR1BW	(ICC_UNSIGN_SHORT	( 0xffffff3A ))
#define DMAC_MAR1B	(ICC_UNSIGN_LONG	( 0xffffff38 ))


/*		The integrated timer-puls unit (5 channels)
		-------------------------------------------

*/
#define ITU_TSTR	(ICC_UNSIGN_CHAR	( 0xffffff60 ))
#define ITU_TSNC	(ICC_UNSIGN_CHAR	( 0xffffff61 ))
#define ITU_TMDR	(ICC_UNSIGN_CHAR	( 0xffffff62 ))
#define ITU_TFCR	(ICC_UNSIGN_CHAR	( 0xffffff63 ))
#define ITU_TOER	(ICC_UNSIGN_CHAR	( 0xffffff90 ))
#define ITU_TOCR	(ICC_UNSIGN_CHAR	( 0xffffff91 ))

#define ITU_TCR0	(ICC_UNSIGN_CHAR	( 0xffffff64 ))
#define ITU_TIOR0	(ICC_UNSIGN_CHAR	( 0xffffff65 ))
#define ITU_TIER0	(ICC_UNSIGN_CHAR	( 0xffffff66 ))
#define ITU_TSR0	(ICC_UNSIGN_CHAR	( 0xffffff67 ))
#define ITU_TCNT0	(ICC_UNSIGN_SHORT	( 0xffffff68 ))
#define ITU_GRA0	(ICC_UNSIGN_SHORT	( 0xffffff6A ))
#define ITU_GRB0	(ICC_UNSIGN_SHORT	( 0xffffff6C ))

#define ITU_TCR1	(ICC_UNSIGN_CHAR	( 0xffffff6e ))
#define ITU_TIOR1	(ICC_UNSIGN_CHAR	( 0xffffff6f ))
#define ITU_TIER1	(ICC_UNSIGN_CHAR	( 0xffffff70 ))
#define ITU_TSR1	(ICC_UNSIGN_CHAR	( 0xffffff71 ))
#define ITU_TCNT1	(ICC_UNSIGN_SHORT	( 0xffffff72 ))
#define ITU_GRA1	(ICC_UNSIGN_SHORT	( 0xffffff74 ))
#define ITU_GRB1	(ICC_UNSIGN_SHORT	( 0xffffff76 ))

#define ITU_TCR2	(ICC_UNSIGN_CHAR	( 0xffffff78 ))
#define ITU_TIOR2	(ICC_UNSIGN_CHAR	( 0xffffff79 ))
#define ITU_TIER2	(ICC_UNSIGN_CHAR	( 0xffffff7a ))
#define ITU_TSR2	(ICC_UNSIGN_CHAR	( 0xffffff7b ))
#define ITU_TCNT2	(ICC_UNSIGN_SHORT	( 0xffffff7c ))
#define ITU_GRA2	(ICC_UNSIGN_SHORT	( 0xffffff7e ))
#define ITU_GRB2	(ICC_UNSIGN_SHORT	( 0xffffff80 ))

#define ITU_TCR3	(ICC_UNSIGN_CHAR	( 0xffffff82 ))
#define ITU_TIOR3	(ICC_UNSIGN_CHAR	( 0xffffff83 ))
#define ITU_TIER3	(ICC_UNSIGN_CHAR	( 0xffffff84 ))
#define ITU_TSR3	(ICC_UNSIGN_CHAR	( 0xffffff85 ))
#define ITU_TCNT3	(ICC_UNSIGN_SHORT	( 0xffffff86 ))
#define ITU_GRA3	(ICC_UNSIGN_SHORT	( 0xffffff88 ))
#define ITU_GRB3	(ICC_UNSIGN_SHORT	( 0xffffff8a ))
#define ITU_BRA3	(ICC_UNSIGN_SHORT	( 0xffffff8c ))
#define ITU_BRB3	(ICC_UNSIGN_SHORT	( 0xffffff8e ))

#define ITU_TCR4	(ICC_UNSIGN_CHAR	( 0xffffff92 ))
#define ITU_TIOR4	(ICC_UNSIGN_CHAR	( 0xffffff93 ))
#define ITU_TIER4	(ICC_UNSIGN_CHAR	( 0xffffff94 ))
#define ITU_TSR4	(ICC_UNSIGN_CHAR	( 0xffffff95 ))
#define ITU_TCNT4	(ICC_UNSIGN_SHORT	( 0xffffff96 ))
#define ITU_GRA4	(ICC_UNSIGN_SHORT	( 0xffffff98 ))
#define ITU_GRB4	(ICC_UNSIGN_SHORT	( 0xffffff9a ))
#define ITU_BRA4	(ICC_UNSIGN_SHORT	( 0xffffff9c ))
#define ITU_BRB4	(ICC_UNSIGN_SHORT	( 0xffffff9e ))


/*		Programmable timing pattern controller
		--------------------------------------
*/

#define TPC_TPMR	(ICC_UNSIGN_CHAR	( 0xffffffa0 ))
#define TPC_TPCR	(ICC_UNSIGN_CHAR	( 0xffffffa1 ))
#define TPC_NDERB	(ICC_UNSIGN_CHAR	( 0xffffffa2 ))
#define TPC_NDERA	(ICC_UNSIGN_CHAR	( 0xffffffa3 ))
#define TPC_NDRB1	(ICC_UNSIGN_CHAR	( 0xffffffa4 ))
#define TPC_NDRA1	(ICC_UNSIGN_CHAR	( 0xffffffa5 ))
#define TPC_NDRB2	(ICC_UNSIGN_CHAR	( 0xffffffa6 ))
#define TPC_NDRA2	(ICC_UNSIGN_CHAR	( 0xffffffa7 ))


/*			Watchdog timer
			--------------
*/

#define WDT_TCSR	(ICC_UNSIGN_CHAR	( 0xffffffa8 ))
#define WDT_TCNT	(ICC_UNSIGN_CHAR	( 0xffffffa9 ))
#define WDT_RSTCSR	(ICC_UNSIGN_CHAR	( 0xffffffab ))

#define WDT_WTCSR	(ICC_UNSIGN_SHORT	( 0xffffffa8 ))
#define WDT_WTCNT	(ICC_UNSIGN_SHORT	( 0xffffffa8 ))
#define WDT_WRSTCSR	(ICC_UNSIGN_SHORT	( 0xffffffaa ))
#define WDT_WRSTOE	(ICC_UNSIGN_SHORT	( 0xffffffaa ))


/*			Refresh controller
			------------------
*/

#define RFSHCR		(ICC_UNSIGN_CHAR	( 0xffffffac ))
#define RTMCSR		(ICC_UNSIGN_CHAR	( 0xffffffad ))
#define RTCNT		(ICC_UNSIGN_CHAR	( 0xffffffae ))
#define RTCOR		(ICC_UNSIGN_CHAR	( 0xffffffaf ))


/*		    Serial communication interface
		    ------------------------------
*/

#define SCI0_SMR	(ICC_UNSIGN_CHAR	( 0xffffffb0 ))
#define SCI0_BRR	(ICC_UNSIGN_CHAR	( 0xffffffb1 ))
#define SCI0_SCR	(ICC_UNSIGN_CHAR	( 0xffffffb2 ))
#define SCI0_TDR	(ICC_UNSIGN_CHAR	( 0xffffffb3 ))
#define SCI0_SSR	(ICC_UNSIGN_CHAR	( 0xffffffb4 ))
#define SCI0_RDR	(ICC_UNSIGN_CHAR	( 0xffffffb5 ))
#define SCI0_SCMR	(ICC_UNSIGN_CHAR	( 0xffffffb6 ))

#define SCI1_SMR	(ICC_UNSIGN_CHAR	( 0xffffffb8 ))
#define SCI1_BRR	(ICC_UNSIGN_CHAR	( 0xffffffb9 ))
#define SCI1_SCR	(ICC_UNSIGN_CHAR	( 0xffffffba ))
#define SCI1_TDR	(ICC_UNSIGN_CHAR	( 0xffffffbb ))
#define SCI1_SSR	(ICC_UNSIGN_CHAR	( 0xffffffbc ))
#define SCI1_RDR	(ICC_UNSIGN_CHAR	( 0xffffffbd ))


/*			Some 8-bit ports....
			--------------------
*/

#define P1DR		(ICC_UNSIGN_CHAR	( 0xffffffc2 ))
#define P1DDR		(ICC_UNSIGN_CHAR	( 0xffffffc0 ))

#define P2CR		(ICC_UNSIGN_CHAR	( 0xffffffd8 ))
#define P2DR		(ICC_UNSIGN_CHAR	( 0xffffffc3 ))
#define P2DDR		(ICC_UNSIGN_CHAR	( 0xffffffc1 ))

#define P3DR		(ICC_UNSIGN_CHAR	( 0xffffffc6 ))
#define P3DDR		(ICC_UNSIGN_CHAR	( 0xffffffc4 ))

#define P4CR		(ICC_UNSIGN_CHAR	( 0xffffffda ))
#define P4DR		(ICC_UNSIGN_CHAR	( 0xffffffc7 ))
#define P4DDR		(ICC_UNSIGN_CHAR	( 0xffffffc5 ))

#define P5CR		(ICC_UNSIGN_CHAR	( 0xffffffdb ))
#define P5DR		(ICC_UNSIGN_CHAR	( 0xffffffca ))
#define P5DDR		(ICC_UNSIGN_CHAR	( 0xffffffc8 ))

#define P6DR		(ICC_UNSIGN_CHAR	( 0xffffffcb ))
#define P6DDR		(ICC_UNSIGN_CHAR	( 0xffffffc9 ))

#define P7DR		(ICC_UNSIGN_CHAR	( 0xffffffce ))

#define P8DR		(ICC_UNSIGN_CHAR	( 0xffffffcf ))
#define P8DDR		(ICC_UNSIGN_CHAR	( 0xffffffcd ))

#define P9DR		(ICC_UNSIGN_CHAR	( 0xffffffd2 ))
#define P9DDR		(ICC_UNSIGN_CHAR	( 0xffffffd0 ))

#define PADR		(ICC_UNSIGN_CHAR	( 0xffffffd3 ))
#define PADDR		(ICC_UNSIGN_CHAR	( 0xffffffd1 ))

#define PBDR		(ICC_UNSIGN_CHAR	( 0xffffffd6 ))
#define PBDDR		(ICC_UNSIGN_CHAR	( 0xffffffd4 ))


/*			D/A converter
			-------------
*/

#define DADR0		(ICC_UNSIGN_CHAR	( 0xffffffdc ))
#define DADR1		(ICC_UNSIGN_CHAR	( 0xffffffdd ))
#define DACR		(ICC_UNSIGN_CHAR	( 0xffffffde ))


/*			A/D converters
			--------------
*/

#define ADDRA		(ICC_UNSIGN_SHORT	( 0xffffffe0 ))
#define ADDRAH		(ICC_UNSIGN_CHAR	( 0xffffffe0 ))
#define ADDRAL		(ICC_UNSIGN_CHAR	( 0xffffffe1 ))
#define ADDRB		(ICC_UNSIGN_SHORT	( 0xffffffe2 ))
#define ADDRBH		(ICC_UNSIGN_CHAR	( 0xffffffe2 ))
#define ADDRBL		(ICC_UNSIGN_CHAR	( 0xffffffe3 ))
#define ADDRC		(ICC_UNSIGN_SHORT	( 0xffffffe4 ))
#define ADDRCH		(ICC_UNSIGN_CHAR	( 0xffffffe4 ))
#define ADDRCL		(ICC_UNSIGN_CHAR	( 0xffffffe5 ))
#define ADDRD		(ICC_UNSIGN_SHORT	( 0xffffffe6 ))
#define ADDRDH		(ICC_UNSIGN_CHAR	( 0xffffffe6 ))
#define ADDRDL		(ICC_UNSIGN_CHAR	( 0xffffffe7 ))
#define ADCSR		(ICC_UNSIGN_CHAR	( 0xffffffe8 ))
#define ADCR		(ICC_UNSIGN_CHAR	( 0xffffffe9 ))


/*			Bus controller
			--------------
*/

#define ABWCR		(ICC_UNSIGN_CHAR	( 0xffffffec ))
#define ASTCR		(ICC_UNSIGN_CHAR	( 0xffffffed ))
#define WCR		(ICC_UNSIGN_CHAR	( 0xffffffee ))
#define WCER		(ICC_UNSIGN_CHAR	( 0xffffffef ))
#define BRCR		(ICC_UNSIGN_CHAR	( 0xfffffff3 ))


/*			System control
			--------------
*/

#define DASTCR		(ICC_UNSIGN_CHAR	( 0xffffff5c ))
#define DIVCR		(ICC_UNSIGN_CHAR	( 0xffffff5d ))
#define MSTCR		(ICC_UNSIGN_CHAR	( 0xffffff5e ))
#define CSCR		(ICC_UNSIGN_CHAR	( 0xffffff5f ))
#define MDCR		(ICC_UNSIGN_CHAR	( 0xfffffff1 ))
#define SYSCR		(ICC_UNSIGN_CHAR	( 0xfffffff2 ))


/*			Interrupt controller
			--------------------
*/

#define ISCR		(ICC_UNSIGN_CHAR	( 0xfffffff4 ))
#define IER		(ICC_UNSIGN_CHAR	( 0xfffffff5 ))
#define ISR		(ICC_UNSIGN_CHAR	( 0xfffffff6 ))
#define IPRA		(ICC_UNSIGN_CHAR	( 0xfffffff8 ))
#define IPRB		(ICC_UNSIGN_CHAR	( 0xfffffff9 ))




/*
        H8/3048 Non Maskable Interrupt Vectors - WYLACZONE


#define RESET			(2-!(__TID__ & 0x01)) * 0x00

#define NMI			(2-!(__TID__ & 0x01)) * 0x0E
#define TRAP0			(2-!(__TID__ & 0x01)) * 0x10
#define TRAP1			(2-!(__TID__ & 0x01)) * 0x12
#define TRAP2			(2-!(__TID__ & 0x01)) * 0x14
#define TRAP3			(2-!(__TID__ & 0x01)) * 0x16

#define IRQ_0			(2-!(__TID__ & 0x01)) * 0x18
#define IRQ_1			(2-!(__TID__ & 0x01)) * 0x1A
#define IRQ_2			(2-!(__TID__ & 0x01)) * 0x1C
#define IRQ_3			(2-!(__TID__ & 0x01)) * 0x1E
#define IRQ_4			(2-!(__TID__ & 0x01)) * 0x20
#define IRQ_5			(2-!(__TID__ & 0x01)) * 0x22

#define WDT_WOVI		(2-!(__TID__ & 0x01)) * 0x28
#define CMI			(2-!(__TID__ & 0x01)) * 0x2A

#define ITU_IMIA0		(2-!(__TID__ & 0x01)) * 0x30
#define ITU_IMIB0		(2-!(__TID__ & 0x01)) * 0x32
#define ITU_OVI0		(2-!(__TID__ & 0x01)) * 0x34

#define ITU_IMIA1		(2-!(__TID__ & 0x01)) * 0x38
#define ITU_IMIB1		(2-!(__TID__ & 0x01)) * 0x3A
#define ITU_OVI1		(2-!(__TID__ & 0x01)) * 0x3C

#define ITU_IMIA2		(2-!(__TID__ & 0x01)) * 0x40
#define ITU_IMIB2		(2-!(__TID__ & 0x01)) * 0x42
#define ITU_OVI2		(2-!(__TID__ & 0x01)) * 0x44

#define ITU_IMIA3		(2-!(__TID__ & 0x01)) * 0x48
#define ITU_IMIB3		(2-!(__TID__ & 0x01)) * 0x4A
#define ITU_OVI3		(2-!(__TID__ & 0x01)) * 0x4C

#define ITU_IMIA4		(2-!(__TID__ & 0x01)) * 0x50
#define ITU_IMIB4		(2-!(__TID__ & 0x01)) * 0x52
#define ITU_OVI4		(2-!(__TID__ & 0x01)) * 0x54

#define DMAC_DEND0A		(2-!(__TID__ & 0x01)) * 0x58
#define DMAC_DEND0B		(2-!(__TID__ & 0x01)) * 0x5A
#define DMAC_DEND1A		(2-!(__TID__ & 0x01)) * 0x5C
#define DMAC_DEND1B		(2-!(__TID__ & 0x01)) * 0x5E

#define SCI_ERI0		(2-!(__TID__ & 0x01)) * 0x68
#define SCI_RXI0		(2-!(__TID__ & 0x01)) * 0x6A
#define SCI_TXI0		(2-!(__TID__ & 0x01)) * 0x6C
#define SCI_TEI0		(2-!(__TID__ & 0x01)) * 0x6E

#define SCI_ERI1		(2-!(__TID__ & 0x01)) * 0x70
#define SCI_RXI1		(2-!(__TID__ & 0x01)) * 0x72
#define SCI_TXI1		(2-!(__TID__ & 0x01)) * 0x74
#define SCI_TEI1		(2-!(__TID__ & 0x01)) * 0x76

#define AD_ADI			(2-!(__TID__ & 0x01)) * 0x78
*/



#endif

/* EOF */
