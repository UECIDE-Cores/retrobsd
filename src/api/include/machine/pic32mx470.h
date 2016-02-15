#ifndef _IO_PIC32MX4_H
#define _IO_PIC32MX4_H

/*--------------------------------------
 * Coprocessor 0 registers.
 */
#define C0_HWRENA	7	/* Enable RDHWR in non-privileged mode */
#define C0_BADVADDR	8	/* Virtual address of last exception */
#define C0_COUNT	9	/* Processor cycle count */
#define C0_COMPARE	11	/* Timer interrupt control */
#define C0_STATUS	12	/* Processor status and control */
#define C0_INTCTL	12	/* Select 1: interrupt control */
#define C0_SRSCTL	12	/* Select 2: GPR shadow set control */
#define C0_SRSMAP	12	/* Select 3: vector to shadow set mapping */
#define C0_CAUSE	13	/* Cause of last exception */
#define C0_EPC		14	/* Program counter at last exception */
#define C0_PRID		15	/* Processor identification (read only) */
#define C0_EBASE	15	/* Select 1: exception base address */
#define C0_CONFIG	16	/* Configuration */
#define C0_CONFIG1	16	/* Select 1: configuration 1 */
#define C0_CONFIG2	16	/* Select 2: configuration 2 */
#define C0_CONFIG3	16	/* Select 3: configuration 3 */
#define C0_DEBUG	23	/* Debug control and status */
#define C0_DEPC		24	/* Program counter at last debug exception */
#define C0_ERROREPC	30	/* Program counter at last error */
#define C0_DESAVE	31	/* Debug handler scratchpad register */

/*
 * Status register.
 */
#define ST_CU0		0x10000000	/* Access to coprocessor 0 allowed (in user mode) */
#define ST_RP		0x08000000	/* Enable reduced power mode */
#define ST_RE		0x02000000	/* Reverse endianness (in user mode) */
#define ST_BEV		0x00400000	/* Exception vectors: bootstrap */
#define ST_SR		0x00100000	/* Soft reset */
#define ST_NMI		0x00080000	/* NMI reset */
#define ST_IPL(x)	((x) << 10)	/* Current interrupt priority level */
#define ST_UM		0x00000010	/* User mode */
#define ST_ERL		0x00000004	/* Error level */
#define ST_EXL		0x00000002	/* Exception level */
#define ST_IE		0x00000001	/* Interrupt enable */

/*
 * Сause register.
 */
#define CA_BD		0x80000000	/* Exception occured in delay slot */
#define CA_TI		0x40000000	/* Timer interrupt is pending */
#define CA_CE		0x30000000	/* Coprocessor exception */
#define CA_DC		0x08000000	/* Disable COUNT register */
#define CA_IV		0x00800000	/* Use special interrupt vector 0x200 */
#define CA_RIPL(r)	((r)>>10 & 63)	/* Requested interrupt priority level */
#define CA_IP1		0x00020000	/* Request software interrupt 1 */
#define CA_IP0		0x00010000	/* Request software interrupt 0 */
#define CA_EXC_CODE	0x0000007c	/* Exception code */

#define CA_Int		0		/* Interrupt */
#define CA_AdEL		(4 << 2)	/* Address error, load or instruction fetch */
#define CA_AdES		(5 << 2)	/* Address error, store */
#define CA_IBE		(6 << 2)	/* Bus error, instruction fetch */
#define CA_DBE		(7 << 2)	/* Bus error, load or store */
#define CA_Sys		(8 << 2)	/* Syscall */
#define CA_Bp		(9 << 2)	/* Breakpoint */
#define CA_RI		(10 << 2)	/* Reserved instruction */
#define CA_CPU		(11 << 2)	/* Coprocessor unusable */
#define CA_Ov		(12 << 2)	/* Arithmetic overflow */
#define CA_Tr		(13 << 2)	/* Trap */

#define DB_DBD          (1 << 31)       /* Debug exception in a branch delay slot */
#define DB_DM           (1 << 30)       /* Debug mode */
#define DB_NODCR        (1 << 29)       /* No dseg present */
#define DB_LSNM         (1 << 28)       /* Load/stores in dseg go to main memory */
#define DB_DOZE         (1 << 27)       /* Processor was in low-power mode */
#define DB_HALT         (1 << 26)       /* Internal system bus clock was running */
#define DB_COUNTDM      (1 << 25)       /* Count register is running in Debug mode */
#define DB_IBUSEP       (1 << 24)       /* Instruction fetch bus error exception */
#define DB_DBUSEP       (1 << 21)       /* Data access bus error exception */
#define DB_IEXI         (1 << 20)       /* Imprecise error exception */
#define DB_VER          (7 << 15)       /* EJTAG version number */
#define DB_DEXCCODE     (0x1f << 10)    /* Cause of exception in Debug mode */
#define DB_SST          (1 << 8)        /* Single step exception enabled */
#define DB_DIBImpr      (1 << 6)        /* Imprecise debug instruction break */
#define DB_DINT         (1 << 5)        /* Debug interrupt exception */
#define DB_DIB          (1 << 4)        /* Debug instruction break exception */
#define DB_DDBS         (1 << 3)        /* Debug data break exception on store */
#define DB_DDBL         (1 << 2)        /* Debug data break exception on load */
#define DB_DBP          (1 << 1)        /* Debug software breakpoint exception */
#define DB_DSS          (1 << 0)        /* Debug single-step exception */

/*--------------------------------------
 * Peripheral registers.
 */
#ifdef __ASSEMBLER__
#define PIC32_R(a)		(0xBF800000 + (a))
#else
#define PIC32_R(a)		*(volatile unsigned*)(0xBF800000 + (a))
#endif

// Bus matrix
#define BMXCON      PIC32_R (0x82000)
#define BMXCONCLR   PIC32_R (0x82004)
#define BMXCONSET   PIC32_R (0x82008)
#define BMXCONINV   PIC32_R (0x8200C)
#define BMXDKPBA    PIC32_R (0x82010)
#define BMXDUDBA    PIC32_R (0x82020)
#define BMXDUPBA    PIC32_R (0x82030)
#define BMXDRMSZ    PIC32_R (0x82040)
#define BMXPUPBA    PIC32_R (0x82050)
#define BMXPFMSZ    PIC32_R (0x82060)
#define BMXBOOTSZ   PIC32_R (0x82070)

// Interrupts
#define INTCON      PIC32_R (0x81000)
#define INTSTAT     PIC32_R (0x81010)
#define IPTMR       PIC32_R (0x81020)
#define IFS0        PIC32_R (0x81030)
#define IFS1        PIC32_R (0x81040)
#define IFS2        PIC32_R (0x81050)
#define IEC0        PIC32_R (0x81060)
#define IEC1        PIC32_R (0x81070)
#define IEC2        PIC32_R (0x81080)
#define IPC0        PIC32_R (0x81090)
#define IPC1        PIC32_R (0x810A0)
#define IPC2        PIC32_R (0x810B0)
#define IPC3        PIC32_R (0x810C0)
#define IPC4        PIC32_R (0x810D0)
#define IPC5        PIC32_R (0x810E0)
#define IPC6        PIC32_R (0x810F0)
#define IPC7        PIC32_R (0x81100)
#define IPC8        PIC32_R (0x81110)
#define IPC9        PIC32_R (0x81120)
#define IPC10       PIC32_R (0x81130)
#define IPC11       PIC32_R (0x81140)

#define IEC(n)      PIC32_R (0x81060+((n)<<4))
#define IECCLR(n)   PIC32_R (0x81064+((n)<<4))
#define IECSET(n)   PIC32_R (0x81068+((n)<<4))
#define IECINV(n)   PIC32_R (0x8106C+((n)<<4))

#define IFS(n)      PIC32_R (0x81030+((n)<<4))
#define IFSCLR(n)   PIC32_R (0x81034+((n)<<4))
#define IFSSET(n)   PIC32_R (0x81038+((n)<<4))
#define IFSINV(n)   PIC32_R (0x8103C+((n)<<4))

#define IPC(n)      PIC32_R (0x81090+((n)<<4)) /* IPC(0..12) - Interrupt Priority Control */
#define IPCCLR(n)   PIC32_R (0x81094+((n)<<4))
#define IPCSET(n)   PIC32_R (0x81098+((n)<<4))
#define IPCINV(n)   PIC32_R (0x8109C+((n)<<4))


// Timers 1 through 5
#define T1CON       PIC32_R (0x00600)
#define TMR1        PIC32_R (0x00610)
#define PR1         PIC32_R (0x00620)
#define T2CON       PIC32_R (0x00800)
#define TMR2        PIC32_R (0x00810)
#define PR2         PIC32_R (0x00820)
#define T3CON       PIC32_R (0x00A00)
#define TMR3        PIC32_R (0x00A10)
#define PR3         PIC32_R (0x00A20)
#define T4CON       PIC32_R (0x00C00)
#define TMR4        PIC32_R (0x00C10)
#define PR4         PIC32_R (0x00C20)
#define T5CON       PIC32_R (0x00E00)
#define TMR5        PIC32_R (0x00E10)
#define PR5         PIC32_R (0x00E20)

// Input capture 1-5
#define IC1CON      PIC32_R (0x02000)
#define IC1BUF      PIC32_R (0x02020)
#define IC2CON      PIC32_R (0x02200)
#define IC2BUF      PIC32_R (0x02220)
#define IC3CON      PIC32_R (0x02400)
#define IC3BUF      PIC32_R (0x02420)
#define IC4CON      PIC32_R (0x02600)
#define IC4BUF      PIC32_R (0x02620)
#define IC5CON      PIC32_R (0x02800)
#define IC5BUF      PIC32_R (0x02820)

// Output compare 1-5
#define OC1CON      PIC32_R (0x03000)
#define OC1R        PIC32_R (0x03010)
#define OC1RS       PIC32_R (0x03020)
#define OC2CON      PIC32_R (0x03200)
#define OC2R        PIC32_R (0x03210)
#define OC2RS       PIC32_R (0x03220)
#define OC3CON      PIC32_R (0x03400)
#define OC3R        PIC32_R (0x03410)
#define OC3RS       PIC32_R (0x03420)
#define OC4CON      PIC32_R (0x03600)
#define OC4R        PIC32_R (0x03610)
#define OC4RS       PIC32_R (0x03620)
#define OC5CON      PIC32_R (0x03800)
#define OC5R        PIC32_R (0x03810)
#define OC5RS       PIC32_R (0x03820)

// I2C1
#define I2C1CON     PIC32_R (0x05000)
#define I2C1STAT    PIC32_R (0x05010)
#define I2C1ADD     PIC32_R (0x05020)
#define I2C1MSK     PIC32_R (0x05030)
#define I2C1BRG     PIC32_R (0x05040)
#define I2C1TRN     PIC32_R (0x05050)
#define I2C1RCV     PIC32_R (0x05060)

// I2C2
#define I2C2CON     PIC32_R (0x05100)
#define I2C2STAT    PIC32_R (0x05110)
#define I2C2ADD     PIC32_R (0x05120)
#define I2C2MSK     PIC32_R (0x05130)
#define I2C2BRG     PIC32_R (0x05140)
#define I2C2TRN     PIC32_R (0x05150)
#define I2C2RCV     PIC32_R (0x05160)

// UART 1
#define U1MODE      PIC32_R (0x06000)
#define U1STA       PIC32_R (0x06010)
#define U1TXREG     PIC32_R (0x06020)
#define U1RXREG     PIC32_R (0x06030)
#define U1BRG       PIC32_R (0x06040)

// UART 2
#define U2MODE      PIC32_R (0x06200)
#define U2STA       PIC32_R (0x06210)
#define U2TXREG     PIC32_R (0x06220)
#define U2RXREG     PIC32_R (0x06230)
#define U2BRG       PIC32_R (0x06240)

// UART 3
#define U3MODE      PIC32_R (0x06400)
#define U3STA       PIC32_R (0x06410)
#define U3TXREG     PIC32_R (0x06420)
#define U3RXREG     PIC32_R (0x06430)
#define U3BRG       PIC32_R (0x06440)

// UART 4
#define U4MODE      PIC32_R (0x06600)
#define U4STA       PIC32_R (0x06610)
#define U4TXREG     PIC32_R (0x06620)
#define U4RXREG     PIC32_R (0x06630)
#define U4BRG       PIC32_R (0x06640)

// UART 5
#define U5MODE      PIC32_R (0x06800)
#define U5STA       PIC32_R (0x06810)
#define U5TXREG     PIC32_R (0x06820)
#define U5RXREG     PIC32_R (0x06830)
#define U5BRG       PIC32_R (0x06840)

// SPI1
#define SPI1CON     PIC32_R (0x05800)
#define SPI1STAT    PIC32_R (0x05810)
#define SPI1BUF     PIC32_R (0x05820)
#define SPI1BRG     PIC32_R (0x05830)
#define SPI1CON2    PIC32_R (0x05840)

// SPI2
#define SPI2CON     PIC32_R (0x05A00)
#define SPI2STAT    PIC32_R (0x05A10)
#define SPI2BUF     PIC32_R (0x05A20)
#define SPI2BRG     PIC32_R (0x05A30)
#define SPI2CON2    PIC32_R (0x05A40)

// ADC
#define AD1CON1     PIC32_R (0x09000)
#define AD1CON2     PIC32_R (0x09010)
#define AD1CON3     PIC32_R (0x09020)
#define AD1CHS      PIC32_R (0x09040)
#define AD1CSSL     PIC32_R (0x09050)
#define AD1BUF0     PIC32_R (0x09070)
#define AD1BUF1     PIC32_R (0x09080)
#define AD1BUF2     PIC32_R (0x09090)
#define AD1BUF3     PIC32_R (0x090A0)
#define AD1BUF4     PIC32_R (0x090B0)
#define AD1BUF5     PIC32_R (0x090C0)
#define AD1BUF6     PIC32_R (0x090D0)
#define AD1BUF7     PIC32_R (0x090E0)
#define AD1BUF8     PIC32_R (0x090F0)
#define AD1BUF9     PIC32_R (0x09100)
#define AD1BUFA     PIC32_R (0x09110)
#define AD1BUFB     PIC32_R (0x09120)
#define AD1BUFC     PIC32_R (0x09130)
#define AD1BUFD     PIC32_R (0x09140)
#define AD1BUFE     PIC32_R (0x09150)
#define AD1BUFF     PIC32_R (0x09160)

// DMA Global
#define DMACON      PIC32_R (0x83000)
#define DMACONCLR   PIC32_R (0x83004)
#define DMACONSET   PIC32_R (0x83008)
#define DMACONINV   PIC32_R (0x8300C)
#define DMASTAT     PIC32_R (0x83010)
#define DMAADDR     PIC32_R (0x83020)

// DMA CRC
#define DCRCCON     PIC32_R (0x83030)
#define DCRCDATA    PIC32_R (0x83040)
#define DCRCXOR     PIC32_R (0x83050)

// DMA 0
#define DCH0CON     PIC32_R (0x83060)
#define DCH0ECON    PIC32_R (0x83070)
#define DCH0INT     PIC32_R (0x83080)
#define DCH0SSA     PIC32_R (0x83090)
#define DCH0DSA     PIC32_R (0x830A0)
#define DCH0SSIZ    PIC32_R (0x830B0)
#define DCH0DSIZ    PIC32_R (0x830C0)
#define DCH0SPTR    PIC32_R (0x830D0)
#define DCH0DPTR    PIC32_R (0x830E0)
#define DCH0CSIZ    PIC32_R (0x830F0)
#define DCH0CPTR    PIC32_R (0x83100)
#define DCH0DAT     PIC32_R (0x83110)

// DMA 1
#define DCH1CON     PIC32_R (0x83120)
#define DCH1ECON    PIC32_R (0x83130)
#define DCH1INT     PIC32_R (0x83140)
#define DCH1SSA     PIC32_R (0x83150)
#define DCH1DSA     PIC32_R (0x83160)
#define DCH1SSIZ    PIC32_R (0x83170)
#define DCH1DSIZ    PIC32_R (0x83180)
#define DCH1SPTR    PIC32_R (0x83190)
#define DCH1DPTR    PIC32_R (0x831A0)
#define DCH1CSIZ    PIC32_R (0x831B0)
#define DCH1CPTR    PIC32_R (0x831C0)
#define DCH1DAT     PIC32_R (0x831D0)

// DMA 2
#define DCH2CON     PIC32_R (0x831E0)
#define DCH2ECON    PIC32_R (0x831F0)
#define DCH2INT     PIC32_R (0x83200)
#define DCH2SSA     PIC32_R (0x83210)
#define DCH2DSA     PIC32_R (0x83220)
#define DCH2SSIZ    PIC32_R (0x83230)
#define DCH2DSIZ    PIC32_R (0x83240)
#define DCH2SPTR    PIC32_R (0x83250)
#define DCH2DPTR    PIC32_R (0x83260)
#define DCH2CSIZ    PIC32_R (0x83270)
#define DCH2CPTR    PIC32_R (0x83280)
#define DCH2DAT     PIC32_R (0x83290)

// DMA 3
#define DCH3CON     PIC32_R (0x832A0)
#define DCH3ECON    PIC32_R (0x832B0)
#define DCH3INT     PIC32_R (0x832C0)
#define DCH3SSA     PIC32_R (0x832D0)
#define DCH3DSA     PIC32_R (0x832E0)
#define DCH3SSIZ    PIC32_R (0x832F0)
#define DCH3DSIZ    PIC32_R (0x83300)
#define DCH3SPTR    PIC32_R (0x83310)
#define DCH3DPTR    PIC32_R (0x83320)
#define DCH3CSIZ    PIC32_R (0x83330)
#define DCH3CPTR    PIC32_R (0x83340)
#define DCH3DAT     PIC32_R (0x83350)

// Comparator
#define CM1CON      PIC32_R (0x0A000)
#define CM2CON      PIC32_R (0x0A010)
#define CMSTAT      PIC32_R (0x0A060)

// Comparator voltage reference
#define CVRCON      PIC32_R (0x09800)

// Flash controller
#define NVMCON      PIC32_R (0x0F400)
#define NVMCONCLR   PIC32_R (0x0F404)
#define NVMCONSET   PIC32_R (0x0F408)
#define NVMCONINV   PIC32_R (0x0F40C)
#define NVMKEY      PIC32_R (0x0F410)
#define NVMADDR     PIC32_R (0x0F420)
#define NVMDATA     PIC32_R (0x0F430)
#define NVMSRCADDR  PIC32_R (0x0F440)

// System controller
#define OSCCON      PIC32_R (0x0F000)
#define OSCTUN      PIC32_R (0x0F010)
#define REFOCON     PIC32_R (0x0F020)
#define REFOTRIM    PIC32_R (0x0F030)
#define WDTCON      PIC32_R (0x00000)
#define RCON        PIC32_R (0x0F600)
#define RCONCLR     PIC32_R (0x0F604)
#define RCONSET     PIC32_R (0x0F608)
#define RCONINV     PIC32_R (0x0F60C)
#define RSWRST      PIC32_R (0x0F610)
#define RSWRSTCLR   PIC32_R (0x0F614)
#define RSWRSTSET   PIC32_R (0x0F618)
#define RSWRSTINV   PIC32_R (0x0F61C)
#define CFGCON      PIC32_R (0x0F200)
#define SYSKEY      PIC32_R (0x0F230)
#define PMD1        PIC32_R (0x0F240)
#define PMD2        PIC32_R (0x0F250)
#define PMD3        PIC32_R (0x0F260)
#define PMD4        PIC32_R (0x0F270)
#define PMD5        PIC32_R (0x0F280)
#define PMD66666    PIC32_R (0x0F290)

// Device configuration
#define DEVCFG0     *(volatile unsigned*)(0xBFC02FFC)
#define DEVCFG1     *(volatile unsigned*)(0xBFC02FF8)
#define DEVCFG2     *(volatile unsigned*)(0xBFC02FF4)
#define DEVCFG3     *(volatile unsigned*)(0xBFC02FF0)

// Device ID revision ID
#define DEVID       PIC32_R (0x0F220)

// PORT A
#define ANSELA      PIC32_R (0x86000)
#define TRISA       PIC32_R (0x86010)
#define PORTA       PIC32_R (0x86020)
#define LATA        PIC32_R (0x86030)
#define ODCA        PIC32_R (0x86040)
#define CNPUA       PIC32_R (0x86050)
#define CNPDA       PIC32_R (0x86060)
#define CNCONA      PIC32_R (0x86070)
#define CNENA       PIC32_R (0x86080)
#define CNSTATA     PIC32_R (0x86090)

// PORT B
#define ANSELB      PIC32_R (0x86100)
#define TRISB       PIC32_R (0x86110)
#define PORTB       PIC32_R (0x86120)
#define LATB        PIC32_R (0x86130)
#define ODCB        PIC32_R (0x86140)
#define CNPUB       PIC32_R (0x86150)
#define CNPDB       PIC32_R (0x86160)
#define CNCONB      PIC32_R (0x86170)
#define CNENB       PIC32_R (0x86180)
#define CNSTATB     PIC32_R (0x86190)

// PORT C
#define ANSELC      PIC32_R (0x86200)
#define TRISC       PIC32_R (0x86210)
#define PORTC       PIC32_R (0x86220)
#define LATC        PIC32_R (0x86230)
#define ODCC        PIC32_R (0x86240)
#define CNPUC       PIC32_R (0x86250)
#define CNPDC       PIC32_R (0x86260)
#define CNCONC      PIC32_R (0x86270)
#define CNENC       PIC32_R (0x86280)
#define CNSTATC     PIC32_R (0x86290)

// PORT D
#define ANSELD      PIC32_R (0x86300)
#define TRISD       PIC32_R (0x86310)
#define PORTD       PIC32_R (0x86320)
#define LATD        PIC32_R (0x86330)
#define ODCD        PIC32_R (0x86340)
#define CNPUD       PIC32_R (0x86350)
#define CNPDD       PIC32_R (0x86360)
#define CNCOND      PIC32_R (0x86370)
#define CNEND       PIC32_R (0x86380)
#define CNSTATD     PIC32_R (0x86390)

// PORT E
#define ANSELE      PIC32_R (0x86400)
#define TRISE       PIC32_R (0x86410)
#define PORTE       PIC32_R (0x86420)
#define LATE        PIC32_R (0x86430)
#define ODCE        PIC32_R (0x86440)
#define CNPUE       PIC32_R (0x86450)
#define CNPDE       PIC32_R (0x86460)
#define CNCONE      PIC32_R (0x86470)
#define CNENE       PIC32_R (0x86480)
#define CNSTATE     PIC32_R (0x86490)

// PORT F
#define ANSELF      PIC32_R (0x86500)
#define TRISF       PIC32_R (0x86510)
#define PORTF       PIC32_R (0x86520)
#define LATF        PIC32_R (0x86530)
#define ODCF        PIC32_R (0x86540)
#define CNPUF       PIC32_R (0x86550)
#define CNPDF       PIC32_R (0x86560)
#define CNCONF      PIC32_R (0x86570)
#define CNENF       PIC32_R (0x86580)
#define CNSTATF     PIC32_R (0x86590)

// PORT G
#define ANSELG      PIC32_R (0x86600)
#define TRISG       PIC32_R (0x86610)
#define PORTG       PIC32_R (0x86620)
#define LATG        PIC32_R (0x86630)
#define ODCG        PIC32_R (0x86640)
#define CNPUG       PIC32_R (0x86650)
#define CNPDG       PIC32_R (0x86660)
#define CNCONG      PIC32_R (0x86670)
#define CNENG       PIC32_R (0x86680)
#define CNSTATG     PIC32_R (0x86690)

// PPS Input Registers
#define INT1R       PIC32_R (0x0FA04)
#define INT2R       PIC32_R (0x0FA08)
#define INT3R       PIC32_R (0x0FA0C)
#define INT4R       PIC32_R (0x0FA10)
#define T2CKR       PIC32_R (0x0FA18)
#define T3CKR       PIC32_R (0x0FA1C)
#define T4CKR       PIC32_R (0x0FA20)
#define T5CKR       PIC32_R (0x0FA24)
#define IC1R        PIC32_R (0x0FA28)
#define IC2R        PIC32_R (0x0FA2C)
#define IC3R        PIC32_R (0x0FA30)
#define IC4R        PIC32_R (0x0FA34)
#define IC5R        PIC32_R (0x0FA38)
#define OCFAR       PIC32_R (0x0FA48)
#define U1RXR       PIC32_R (0x0FA50)
#define U1CTSR      PIC32_R (0x0FA54)
#define U2RXR       PIC32_R (0x0FA58)
#define U2CTSR      PIC32_R (0x0FA5C)
#define U3RXR       PIC32_R (0x0FA60)
#define U3CTSR      PIC32_R (0x0FA64)
#define U4RXR       PIC32_R (0x0FA68)
#define U4CTSR      PIC32_R (0x0FA6C)
#define U5RXR       PIC32_R (0x0FA70)
#define U5CTSR      PIC32_R (0x0FA74)
#define SDI1R       PIC32_R (0x0FA84)
#define SS1R        PIC32_R (0x0FA88)
#define SDI2R       PIC32_R (0x0FA90)
#define SS2R        PIC32_R (0x0FA94)
#define REFCLKIR    PIC32_R (0x0FAD0)

// PPS Output Registers
#define RPA14R      PIC32_R (0x0FB38)
#define RPA15R      PIC32_R (0x0FB3C)
#define RPB0R       PIC32_R (0x0FB40)
#define RPB1R       PIC32_R (0x0FB44)
#define RPB2R       PIC32_R (0x0FB48)
#define RPB3R       PIC32_R (0x0FB4C)
#define RPB5R       PIC32_R (0x0FB54)
#define RPB6R       PIC32_R (0x0FB58)
#define RPB7R       PIC32_R (0x0FB5C)
#define RPB8R       PIC32_R (0x0FB60)
#define RPB9R       PIC32_R (0x0FB64)
#define RPB10R      PIC32_R (0x0FB68)
#define RPB14R      PIC32_R (0x0FB78)
#define RPB15R      PIC32_R (0x0FB7C)
#define RPC1R       PIC32_R (0x0FB84)
#define RPC2R       PIC32_R (0x0FB88)
#define RPC3R       PIC32_R (0x0FB8C)
#define RPC4R       PIC32_R (0x0FB90)
#define RPC13R      PIC32_R (0x0FBB4)
#define RPC14R      PIC32_R (0x0FBB8)
#define RPD0R       PIC32_R (0x0FBC0)
#define RPD1R       PIC32_R (0x0FBC4)
#define RPD2R       PIC32_R (0x0FBC8)
#define RPD3R       PIC32_R (0x0FBCC)
#define RPD4R       PIC32_R (0x0FBD0)
#define RPD5R       PIC32_R (0x0FBD4)
#define RPD8R       PIC32_R (0x0FBE0)
#define RPD9R       PIC32_R (0x0FBE4)
#define RPD10R      PIC32_R (0x0FBE8)
#define RPD11R      PIC32_R (0x0FBEC)
#define RPD12R      PIC32_R (0x0FBF0)
#define RPD14R      PIC32_R (0x0FBF8)
#define RPD15R      PIC32_R (0x0FBFC)
#define RPE3R       PIC32_R (0x0FC0C)
#define RPE5R       PIC32_R (0x0FC14)
#define RPE8R       PIC32_R (0x0FC20)
#define RPE9R       PIC32_R (0x0FC24)
#define RPF0R       PIC32_R (0x0FC40)
#define RPF1R       PIC32_R (0x0FC44)
#define RPF2R       PIC32_R (0x0FC48)
#define RPF3R       PIC32_R (0x0FC4C)
#define RPF4R       PIC32_R (0x0FC50)
#define RPF5R       PIC32_R (0x0FC54)
#define RPF6R       PIC32_R (0x0FC58)
#define RPF8R       PIC32_R (0x0FC60)
#define RPF12R      PIC32_R (0x0FC70)
#define RPF13R      PIC32_R (0x0FC74)
#define RPG0R       PIC32_R (0x0FC80)
#define RPG1R       PIC32_R (0x0FC84)
#define RPG6R       PIC32_R (0x0FC98)
#define RPG7R       PIC32_R (0x0FC9C)
#define RPG8R       PIC32_R (0x0FCA0)
#define RPG9R       PIC32_R (0x0FCA4)

// Parallel Master Port
#define PMCON       PIC32_R (0x07000)
#define PMMODE      PIC32_R (0x07010)
#define PMADDR      PIC32_R (0x07020)
#define PMDOUT      PIC32_R (0x07030)
#define PMDIN       PIC32_R (0x07040)
#define PMAEN       PIC32_R (0x07050)
#define PMSTAT      PIC32_R (0x07060)

// Prefetch 
#define CHECON      PIC32_R (0x84000)
#define CHECONCLR   PIC32_R (0x84004)
#define CHECONSET   PIC32_R (0x84008)
#define CHECONINV   PIC32_R (0x8400C)
#define CHEACC      PIC32_R (0x84010)
#define CHETAG      PIC32_R (0x84020)
#define CHEMSK      PIC32_R (0x84030)
#define CHEW0       PIC32_R (0x84040)
#define CHEW1       PIC32_R (0x84050)
#define CHEW2       PIC32_R (0x84060)
#define CHEW3       PIC32_R (0x84070)
#define CHELRU      PIC32_R (0x84080)
#define CHEHIT      PIC32_R (0x84090)
#define CHEMIS      PIC32_R (0x840A0)
#define CHEPFABT    PIC32_R (0x840C0)

// RTCC
#define RTCCON      PIC32_R (0x00200)
#define RTCALRM     PIC32_R (0x00210)
#define RTCTIME     PIC32_R (0x00220)
#define RTCDATE     PIC32_R (0x00230)
#define ALRMTIME    PIC32_R (0x00240)
#define ALRMDATE    PIC32_R (0x00250)

// CTMU
#define CTMUCON     PIC32_R (0x0A200)

// USB
#define U1OTGIR     PIC32_R (0x85040)
#define U1OTGIE     PIC32_R (0x85050)
#define U1OTGSTAT   PIC32_R (0x85060)
#define U1OTGCON    PIC32_R (0x85070)
#define U1PWRC      PIC32_R (0x85080)
#define U1IR        PIC32_R (0x85200)
#define U1IE        PIC32_R (0x85210)
#define U1EIR       PIC32_R (0x85220)
#define U1EIE       PIC32_R (0x85230)
#define U1STAT      PIC32_R (0x85240)
#define U1CON       PIC32_R (0x85250)
#define U1ADDR      PIC32_R (0x85260)
#define U1BDTP1     PIC32_R (0x85270)
#define U1FRML      PIC32_R (0x85280)
#define U1FRMH      PIC32_R (0x85290)
#define U1TOK       PIC32_R (0x852A0)
#define U1SOF       PIC32_R (0x852B0)
#define U1BDTP2     PIC32_R (0x852C0)
#define U1BDTP3     PIC32_R (0x852D0)
#define U1CNFG1     PIC32_R (0x852E0)
#define U1EP0       PIC32_R (0x85300)
#define U1EP1       PIC32_R (0x85310)
#define U1EP2       PIC32_R (0x85320)
#define U1EP3       PIC32_R (0x85330)
#define U1EP4       PIC32_R (0x85340)
#define U1EP5       PIC32_R (0x85350)
#define U1EP6       PIC32_R (0x85360)
#define U1EP7       PIC32_R (0x85370)
#define U1EP8       PIC32_R (0x85380)
#define U1EP9       PIC32_R (0x85390)
#define U1EP10      PIC32_R (0x853A0)
#define U1EP11      PIC32_R (0x853B0)
#define U1EP12      PIC32_R (0x853C0)
#define U1EP13      PIC32_R (0x853D0)
#define U1EP14      PIC32_R (0x853E0)
#define U1EP15      PIC32_R (0x853F0)
#define U1EP(n)     PIC32_R (0x85300 + (n << 4)) /* Endpoint control */

/*
 * USB Power control register.
 */
#define PIC32_U1PWRC_USBPWR 0x0001 /* USB operation enable */
#define PIC32_U1PWRC_USUSPEND   0x0002 /* USB suspend mode */
#define PIC32_U1PWRC_USLPGRD    0x0010 /* USB sleep entry guard */
#define PIC32_U1PWRC_UACTPND    0x0080 /* UAB activity pending */

/*
 * USB Pending interrupt register.
 * USB Interrupt enable register.
 */
#define PIC32_U1I_DETACH    0x0001 /* Detach (host mode) */
#define PIC32_U1I_URST      0x0001 /* USB reset (device mode) */
#define PIC32_U1I_UERR      0x0002 /* USB error condition */
#define PIC32_U1I_SOF       0x0004 /* SOF token  */
#define PIC32_U1I_TRN       0x0008 /* Token processing complete */
#define PIC32_U1I_IDLE      0x0010 /* Idle detect */
#define PIC32_U1I_RESUME    0x0020 /* Resume */
#define PIC32_U1I_ATTACH    0x0040 /* Peripheral attach */
#define PIC32_U1I_STALL     0x0080 /* STALL handshake */

/*
 * USB OTG interrupt flags register.
 * USB OTG interrupt enable register.
 */
#define PIC32_U1OTGI_VBUSVD 0x0001 /* A-device Vbus change */
#define PIC32_U1OTGI_SESEND 0x0004 /* B-device Vbus change */
#define PIC32_U1OTGI_SESVD  0x0008 /* Session valid change */
#define PIC32_U1OTGI_ACTV   0x0010 /* Bus activity indicator */
#define PIC32_U1OTGI_LSTATE 0x0020 /* Line state stable */
#define PIC32_U1OTGI_T1MSEC 0x0040 /* 1 millisecond timer expired */
#define PIC32_U1OTGI_ID     0x0080 /* ID state change */

#define PIC32_U1OTGSTAT_VBUSVD  0x0001 /*  */
#define PIC32_U1OTGSTAT_SESEND  0x0004 /*  */
#define PIC32_U1OTGSTAT_SESVD   0x0008 /*  */
#define PIC32_U1OTGSTAT_LSTATE  0x0020 /*  */
#define PIC32_U1OTGSTAT_ID  0x0080 /*  */

#define PIC32_U1OTGCON_VBUSDIS  0x0001 /*  */
#define PIC32_U1OTGCON_VBUSCHG  0x0002 /*  */
#define PIC32_U1OTGCON_OTGEN    0x0004 /*  */
#define PIC32_U1OTGCON_VBUSON   0x0008 /*  */
#define PIC32_U1OTGCON_DMPULDWN 0x0010 /*  */
#define PIC32_U1OTGCON_DPPULDWN 0x0020 /*  */
#define PIC32_U1OTGCON_DMPULUP  0x0040 /*  */
#define PIC32_U1OTGCON_DPPULUP  0x0080 /*  */

#define PIC32_U1EI_PID      0x0001 /*  */
#define PIC32_U1EI_CRC5     0x0002 /*  */
#define PIC32_U1EI_EOF      0x0002 /*  */
#define PIC32_U1EI_CRC16    0x0004 /*  */
#define PIC32_U1EI_DFN8     0x0008 /*  */
#define PIC32_U1EI_BTO      0x0010 /*  */
#define PIC32_U1EI_DMA      0x0020 /*  */
#define PIC32_U1EI_BMX      0x0040 /*  */
#define PIC32_U1EI_BTS      0x0080 /*  */

#define PIC32_U1STAT_PPBI   0x0004 /*  */
#define PIC32_U1STAT_DIR    0x0008 /*  */
#define PIC32_U1STAT_ENDPT(x)   (((x) >> 4) & 0xF) /*  */

#define PIC32_U1ADDR_DEVADDR    0x007F /*  */
#define PIC32_U1ADDR_USBADDR0   0x0001 /*  */
#define PIC32_U1ADDR_DEVADDR1   0x0002 /*  */
#define PIC32_U1ADDR_DEVADDR2   0x0004 /*  */
#define PIC32_U1ADDR_DEVADDR3   0x0008 /*  */
#define PIC32_U1ADDR_DEVADDR4   0x0010 /*  */
#define PIC32_U1ADDR_DEVADDR5   0x0020 /*  */
#define PIC32_U1ADDR_DEVADDR6   0x0040 /*  */
#define PIC32_U1ADDR_LSPDEN 0x0080 /*  */

#define PIC32_U1FRML_FRM0   0x0001 /*  */
#define PIC32_U1FRML_FRM1   0x0002 /*  */
#define PIC32_U1FRML_FRM2   0x0004 /*  */
#define PIC32_U1FRML_FRM3   0x0008 /*  */
#define PIC32_U1FRML_FRM4   0x0010 /*  */
#define PIC32_U1FRML_FRM5   0x0020 /*  */
#define PIC32_U1FRML_FRM6   0x0040 /*  */
#define PIC32_U1FRML_FRM7   0x0080 /*  */

#define PIC32_U1FRMH_FRM8   0x0001 /*  */
#define PIC32_U1FRMH_FRM9   0x0002 /*  */
#define PIC32_U1FRMH_FRM10  0x0004 /*  */

#define PIC32_U1TOK_EP0     0x0001 /*  */
#define PIC32_U1TOK_EP      0x000F /*  */
#define PIC32_U1TOK_EP1     0x0002 /*  */
#define PIC32_U1TOK_EP2     0x0004 /*  */
#define PIC32_U1TOK_EP3     0x0008 /*  */
#define PIC32_U1TOK_PID0    0x0010 /*  */
#define PIC32_U1TOK_PID     0x00F0 /*  */
#define PIC32_U1TOK_PID1    0x0020 /*  */
#define PIC32_U1TOK_PID2    0x0040 /*  */
#define PIC32_U1TOK_PID3    0x0080 /*  */

#define PIC32_U1CNFG1_USBSIDL   0x0010 /*  */
#define PIC32_U1CNFG1_USBFRZ    0x0020 /*  */
#define PIC32_U1CNFG1_UOEMON    0x0040 /*  */
#define PIC32_U1CNFG1_UTEYE 0x0080 /*  */

#define PIC32_U1EP_EPHSHK   0x0001 /*  */
#define PIC32_U1EP_EPSTALL  0x0002 /*  */
#define PIC32_U1EP_EPTXEN   0x0004 /*  */
#define PIC32_U1EP_EPRXEN   0x0008 /*  */
#define PIC32_U1EP_EPCONDIS 0x0010 /*  */
#define PIC32_U1EP_RETRYDIS 0x0040 /*  */
#define PIC32_U1EP_LSPD     0x0080 /*  */

/* DB status field values */
#define PIC32_DB_BSTALL     (1 << 2)
#define PIC32_DB_DTS        (1 << 3)
#define PIC32_DB_NINC       (1 << 4)
#define PIC32_DB_KEEP       (1 << 5)
#define PIC32_DB_DATA1      (1 << 6)
#define PIC32_DB_UOWN       (1 << 7)
#define PIC32_DB_GET_PID(x) (((x) >> 2) & 0xF)
#define PIC32_DB_SET_PID(x) (((x) & 0xF) << 2)
#define PIC32_DB_GET_COUNT(x)   (((x) >> 16) & 0x3FF)
#define PIC32_DB_SET_COUNT(x)   (((x) & 0x3FF) << 16)

/*
 * USB Control register.
 */
#define PIC32_U1CON_USBEN   0x0001 /* USB module enable (device mode) */
#define PIC32_U1CON_SOFEN   0x0001 /* SOF sent every 1 ms (host mode) */
#define PIC32_U1CON_PPBRST  0x0002 /* Ping-pong buffers reset */
#define PIC32_U1CON_RESUME  0x0004 /* Resume signaling enable */
#define PIC32_U1CON_HOSTEN  0x0008 /* Host mode enable */
#define PIC32_U1CON_USBRST  0x0010 /* USB reset */
#define PIC32_U1CON_PKTDIS  0x0020 /* Packet transfer disable */
#define PIC32_U1CON_TOKBUSY 0x0020 /* Token busy indicator */
#define PIC32_U1CON_SE0     0x0040 /* Single ended zero detected */
#define PIC32_U1CON_JSTATE  0x0080 /* Live differential receiver JSTATE flag */


/*
 * UART Mode register.
 */
#define PIC32_UMODE_STSEL	0x0001	/* 2 Stop bits */
#define PIC32_UMODE_PDSEL	0x0006	/* Bitmask: */
#define PIC32_UMODE_PDSEL_8NPAR	0x0000	/* 8-bit data, no parity */
#define PIC32_UMODE_PDSEL_8EVEN	0x0002	/* 8-bit data, even parity */
#define PIC32_UMODE_PDSEL_8ODD	0x0004	/* 8-bit data, odd parity */
#define PIC32_UMODE_PDSEL_9NPAR	0x0006	/* 9-bit data, no parity */
#define PIC32_UMODE_BRGH	0x0008	/* High Baud Rate Enable */
#define PIC32_UMODE_RXINV	0x0010	/* Receive Polarity Inversion */
#define PIC32_UMODE_ABAUD	0x0020	/* Auto-Baud Enable */
#define PIC32_UMODE_LPBACK	0x0040	/* UARTx Loopback Mode */
#define PIC32_UMODE_WAKE	0x0080	/* Wake-up on start bit during Sleep Mode */
#define PIC32_UMODE_UEN		0x0300	/* Bitmask: */
#define PIC32_UMODE_UEN_RTS	0x0100	/* Using UxRTS pin */
#define PIC32_UMODE_UEN_RTSCTS	0x0200	/* Using UxCTS and UxRTS pins */
#define PIC32_UMODE_UEN_BCLK	0x0300	/* Using UxBCLK pin */
#define PIC32_UMODE_RTSMD	0x0800	/* UxRTS Pin Simplex mode */
#define PIC32_UMODE_IREN	0x1000	/* IrDA Encoder and Decoder Enable bit */
#define PIC32_UMODE_SIDL	0x2000	/* Stop in Idle Mode */
#define PIC32_UMODE_FRZ		0x4000	/* Freeze in Debug Exception Mode */
#define PIC32_UMODE_ON		0x8000	/* UART Enable */

/*
 * UART Control and status register.
 */
#define PIC32_USTA_URXDA	0x00000001 /* Receive Data Available (read-only) */
#define PIC32_USTA_OERR		0x00000002 /* Receive Buffer Overrun */
#define PIC32_USTA_FERR		0x00000004 /* Framing error detected (read-only) */
#define PIC32_USTA_PERR		0x00000008 /* Parity error detected (read-only) */
#define PIC32_USTA_RIDLE	0x00000010 /* Receiver is idle (read-only) */
#define PIC32_USTA_ADDEN	0x00000020 /* Address Detect mode */
#define PIC32_USTA_URXISEL	0x000000C0 /* Bitmask: receive interrupt is set when... */
#define PIC32_USTA_URXISEL_NEMP	0x00000000 /* ...receive buffer is not empty */
#define PIC32_USTA_URXISEL_HALF	0x00000040 /* ...receive buffer becomes 1/2 full */
#define PIC32_USTA_URXISEL_3_4	0x00000080 /* ...receive buffer becomes 3/4 full */
#define PIC32_USTA_TRMT		0x00000100 /* Transmit shift register is empty (read-only) */
#define PIC32_USTA_UTXBF	0x00000200 /* Transmit buffer is full (read-only) */
#define PIC32_USTA_UTXEN	0x00000400 /* Transmit Enable */
#define PIC32_USTA_UTXBRK	0x00000800 /* Transmit Break */
#define PIC32_USTA_URXEN	0x00001000 /* Receiver Enable */
#define PIC32_USTA_UTXINV	0x00002000 /* Transmit Polarity Inversion */
#define PIC32_USTA_UTXISEL	0x0000C000 /* Bitmask: TX interrupt is generated when... */
#define PIC32_USTA_UTXISEL_1	0x00000000 /* ...the transmit buffer contains at least one empty space */
#define PIC32_USTA_UTXISEL_ALL	0x00004000 /* ...all characters have been transmitted */
#define PIC32_USTA_UTXISEL_EMP	0x00008000 /* ...the transmit buffer becomes empty */
#define PIC32_USTA_ADDR		0x00FF0000 /* Automatic Address Mask */
#define PIC32_USTA_ADM_EN	0x01000000 /* Automatic Address Detect */

/*
 * Compute the 16-bit baud rate divisor, given
 * the bus frequency and baud rate.
 * Round to the nearest integer.
 */
#define PIC32_BRG_BAUD(fr,bd)	((((fr)/8 + (bd)) / (bd) / 2) - 1)

/*
 * USB OTG interrupt flags register.
 * USB OTG interrupt enable register.
 */
#define PIC32_U1OTGI_VBUSVD	0x0001 /* A-device Vbus change */
#define PIC32_U1OTGI_SESEND	0x0004 /* B-device Vbus change */
#define PIC32_U1OTGI_SESVD	0x0008 /* Session valid change */
#define PIC32_U1OTGI_ACTV	0x0010 /* Bus activity indicator */
#define PIC32_U1OTGI_LSTATE	0x0020 /* Line state stable */
#define PIC32_U1OTGI_T1MSEC	0x0040 /* 1 millisecond timer expired */
#define PIC32_U1OTGI_ID		0x0080 /* ID state change */

#define PIC32_U1OTGSTAT_VBUSVD	0x0001 /*  */
#define PIC32_U1OTGSTAT_SESEND	0x0004 /*  */
#define PIC32_U1OTGSTAT_SESVD	0x0008 /*  */
#define PIC32_U1OTGSTAT_LSTATE	0x0020 /*  */
#define PIC32_U1OTGSTAT_ID	0x0080 /*  */

#define PIC32_U1OTGCON_VBUSDIS	0x0001 /*  */
#define PIC32_U1OTGCON_VBUSCHG	0x0002 /*  */
#define PIC32_U1OTGCON_OTGEN	0x0004 /*  */
#define PIC32_U1OTGCON_VBUSON	0x0008 /*  */
#define PIC32_U1OTGCON_DMPULDWN	0x0010 /*  */
#define PIC32_U1OTGCON_DPPULDWN	0x0020 /*  */
#define PIC32_U1OTGCON_DMPULUP	0x0040 /*  */
#define PIC32_U1OTGCON_DPPULUP	0x0080 /*  */

#define PIC32_U1EI_PID		0x0001 /*  */
#define PIC32_U1EI_CRC5		0x0002 /*  */
#define PIC32_U1EI_EOF		0x0002 /*  */
#define PIC32_U1EI_CRC16	0x0004 /*  */
#define PIC32_U1EI_DFN8		0x0008 /*  */
#define PIC32_U1EI_BTO		0x0010 /*  */
#define PIC32_U1EI_DMA		0x0020 /*  */
#define PIC32_U1EI_BMX		0x0040 /*  */
#define PIC32_U1EI_BTS		0x0080 /*  */

#define PIC32_U1STAT_PPBI	0x0004 /*  */
#define PIC32_U1STAT_DIR	0x0008 /*  */
#define PIC32_U1STAT_ENDPT(x)	(((x) >> 4) & 0xF) /*  */

#define PIC32_U1ADDR_DEVADDR	0x007F /*  */
#define PIC32_U1ADDR_USBADDR0	0x0001 /*  */
#define PIC32_U1ADDR_DEVADDR1	0x0002 /*  */
#define PIC32_U1ADDR_DEVADDR2	0x0004 /*  */
#define PIC32_U1ADDR_DEVADDR3	0x0008 /*  */
#define PIC32_U1ADDR_DEVADDR4	0x0010 /*  */
#define PIC32_U1ADDR_DEVADDR5	0x0020 /*  */
#define PIC32_U1ADDR_DEVADDR6	0x0040 /*  */
#define PIC32_U1ADDR_LSPDEN	0x0080 /*  */

#define PIC32_U1FRML_FRM0	0x0001 /*  */
#define PIC32_U1FRML_FRM1	0x0002 /*  */
#define PIC32_U1FRML_FRM2	0x0004 /*  */
#define PIC32_U1FRML_FRM3	0x0008 /*  */
#define PIC32_U1FRML_FRM4	0x0010 /*  */
#define PIC32_U1FRML_FRM5	0x0020 /*  */
#define PIC32_U1FRML_FRM6	0x0040 /*  */
#define PIC32_U1FRML_FRM7	0x0080 /*  */

#define PIC32_U1FRMH_FRM8	0x0001 /*  */
#define PIC32_U1FRMH_FRM9	0x0002 /*  */
#define PIC32_U1FRMH_FRM10	0x0004 /*  */

#define PIC32_U1TOK_EP0		0x0001 /*  */
#define PIC32_U1TOK_EP		0x000F /*  */
#define PIC32_U1TOK_EP1		0x0002 /*  */
#define PIC32_U1TOK_EP2		0x0004 /*  */
#define PIC32_U1TOK_EP3		0x0008 /*  */
#define PIC32_U1TOK_PID0	0x0010 /*  */
#define PIC32_U1TOK_PID		0x00F0 /*  */
#define PIC32_U1TOK_PID1	0x0020 /*  */
#define PIC32_U1TOK_PID2	0x0040 /*  */
#define PIC32_U1TOK_PID3	0x0080 /*  */

#define PIC32_U1CNFG1_USBSIDL	0x0010 /*  */
#define PIC32_U1CNFG1_USBFRZ	0x0020 /*  */
#define PIC32_U1CNFG1_UOEMON	0x0040 /*  */
#define PIC32_U1CNFG1_UTEYE	0x0080 /*  */

#define PIC32_U1EP_EPHSHK	0x0001 /*  */
#define PIC32_U1EP_EPSTALL	0x0002 /*  */
#define PIC32_U1EP_EPTXEN	0x0004 /*  */
#define PIC32_U1EP_EPRXEN	0x0008 /*  */
#define PIC32_U1EP_EPCONDIS	0x0010 /*  */
#define PIC32_U1EP_RETRYDIS	0x0040 /*  */
#define PIC32_U1EP_LSPD		0x0080 /*  */

/* DB status field values */
#define PIC32_DB_BSTALL		(1 << 2)
#define PIC32_DB_DTS		(1 << 3)
#define PIC32_DB_NINC		(1 << 4)
#define PIC32_DB_KEEP		(1 << 5)
#define PIC32_DB_DATA1		(1 << 6)
#define PIC32_DB_UOWN		(1 << 7)
#define PIC32_DB_GET_PID(x)	(((x) >> 2) & 0xF)
#define PIC32_DB_SET_PID(x)	(((x) & 0xF) << 2)
#define PIC32_DB_GET_COUNT(x)	(((x) >> 16) & 0x3FF)
#define PIC32_DB_SET_COUNT(x)	(((x) & 0x3FF) << 16)

/*
 * SPI Control register.
 */
#define PIC32_SPICON_MSTEN	0x00000020	/* Master mode */
#define PIC32_SPICON_CKP	0x00000040      /* Idle clock is high level */
#define PIC32_SPICON_SSEN	0x00000080      /* Slave mode: SSx pin enable */
#define PIC32_SPICON_CKE	0x00000100      /* Output data changes on
						 * transition from active clock
						 * state to Idle clock state */
#define PIC32_SPICON_SMP	0x00000200      /* Master mode: input data sampled
						 * at end of data output time. */
#define PIC32_SPICON_MODE16	0x00000400      /* 16-bit data width */
#define PIC32_SPICON_MODE32	0x00000800      /* 32-bit data width */
#define PIC32_SPICON_DISSDO	0x00001000      /* SDOx pin is not used */
#define PIC32_SPICON_SIDL	0x00002000      /* Stop in Idle mode */
#define PIC32_SPICON_FRZ	0x00004000      /* Freeze in Debug mode */
#define PIC32_SPICON_ON		0x00008000      /* SPI Peripheral is enabled */
#define PIC32_SPICON_ENHBUF	0x00010000      /* Enhanced buffer enable */
#define PIC32_SPICON_SPIFE	0x00020000      /* Frame synchronization pulse
						 * coincides with the first bit clock */
#define PIC32_SPICON_FRMPOL	0x20000000      /* Frame pulse is active-high */
#define PIC32_SPICON_FRMSYNC	0x40000000      /* Frame sync pulse input (Slave mode) */
#define PIC32_SPICON_FRMEN	0x80000000      /* Framed SPI support */

/*
 * SPI Status register.
 */
#define PIC32_SPISTAT_SPIRBF	0x00000001      /* Receive buffer is full */
#define PIC32_SPISTAT_SPITBF	0x00000002      /* Transmit buffer is full */
#define PIC32_SPISTAT_SPITBE	0x00000008      /* Transmit buffer is empty */
#define PIC32_SPISTAT_SPIRBE    0x00000020      /* Receive buffer is empty */
#define PIC32_SPISTAT_SPIROV	0x00000040      /* Receive overflow flag */
#define PIC32_SPISTAT_SPIBUSY	0x00000800      /* SPI is busy */

/*
 * Reset control register.
 */
#define PIC32_RCON_POR          0x00000001
#define PIC32_RCON_BOR          0x00000002
#define PIC32_RCON_IDLE         0x00000004
#define PIC32_RCON_SLEEP        0x00000008
#define PIC32_RCON_WDTO         0x00000010
#define PIC32_RCON_SWR          0x00000040
#define PIC32_RCON_EXTR         0x00000080
#define PIC32_RCON_VREGS        0x00000100
#define PIC32_RCON_CMR          0x00000200

#define PIC32_NVMCON_NVMOP      0x0000000F
#define PIC32_NVMCON_NOP                 0 /* No operation */
#define PIC32_NVMCON_WORD_PGM            1 /* Word program */
#define PIC32_NVMCON_ROW_PGM             3 /* Row program */
#define PIC32_NVMCON_PAGE_ERASE          4 /* Page erase */

#define PIC32_NVMCON_LVDSTAT    0x00000800
#define PIC32_NVMCON_LVDERR     0x00001000
#define PIC32_NVMCON_WRERR      0x00002000
#define PIC32_NVMCON_WREN       0x00004000
#define PIC32_NVMCON_WR         0x00008000


#define BLRKEY      *(volatile unsigned*)(0x80000000)

/*--------------------------------------
 * Configuration registers.
 */

#define PIC32_DEVCFG(cfg0, cfg1, cfg2, cfg3) \
    asm (".section .config"); \
    unsigned __DEVCFG0 __attribute__ ((section (".config0"))) = (cfg0); \
    unsigned __DEVCFG1 __attribute__ ((section (".config1"))) = (cfg1); \
    unsigned __DEVCFG2 __attribute__ ((section (".config2"))) = (cfg2); \
    unsigned __DEVCFG3 __attribute__ ((section (".config3"))) = (cfg3);

/*
 * Config0 register at 1fc02ffc, inverted.
 */
#define DEVCFG0_DEBUG_MASK      0x00000003 /* Debugger enable bits */
#define DEVCFG0_DEBUG_DISABLED  0x00000000 /* Debugger disabled */
#define DEVCFG0_DEBUG_ENABLED   0x00000002 /* Debugger enabled */
#define DEVCFG0_ICESEL          0x00000008 /* Use PGC1/PGD1 (default PGC2/PGD2) */
#define DEVCFG0_PWP_MASK        0x000ff000 /* Program flash write protect */
#define DEVCFG0_BWP             0x01000000 /* Boot flash write protect */
#define DEVCFG0_CP              0x10000000 /* Code protect */

/*
 * Config1 register at 1fc02ff8.
 */
#define DEVCFG1_UNUSED          0xff600858
#define DEVCFG1_FNOSC_MASK      0x00000007 /* Oscillator selection */
#define DEVCFG1_FNOSC_FRC       0x00000000 /* Fast RC */
#define DEVCFG1_FNOSC_FRCDIVPLL 0x00000001 /* Fast RC with divide-by-N and PLL */
#define DEVCFG1_FNOSC_PRI       0x00000002 /* Primary oscillator XT, HS, EC */
#define DEVCFG1_FNOSC_PRIPLL    0x00000003 /* Primary with PLL */
#define DEVCFG1_FNOSC_SEC       0x00000004 /* Secondary oscillator */
#define DEVCFG1_FNOSC_LPRC      0x00000005 /* Low-power RC */
#define DEVCFG1_FNOSC_FRCDIV    0x00000007 /* Fast RC with divide-by-N */
#define DEVCFG1_FSOSCEN         0x00000020 /* Secondary oscillator enable */
#define DEVCFG1_IESO            0x00000080 /* Internal-external switch over */
#define DEVCFG1_POSCMOD_MASK    0x00000300 /* Primary oscillator config */
#define DEVCFG1_POSCMOD_EXT     0x00000000 /* External mode */
#define DEVCFG1_POSCMOD_XT      0x00000100 /* XT oscillator */
#define DEVCFG1_POSCMOD_HS      0x00000200 /* HS oscillator */
#define DEVCFG1_POSCMOD_DISABLE 0x00000300 /* Disabled */
#define DEVCFG1_OSCIOFNC        0x00000400 /* CLKO output active */
#define DEVCFG1_FPBDIV_MASK     0x00003000 /* Peripheral bus clock divisor */
#define DEVCFG1_FPBDIV_1        0x00000000 /* SYSCLK / 1 */
#define DEVCFG1_FPBDIV_2        0x00001000 /* SYSCLK / 2 */
#define DEVCFG1_FPBDIV_4        0x00002000 /* SYSCLK / 4 */
#define DEVCFG1_FPBDIV_8        0x00003000 /* SYSCLK / 8 */
#define DEVCFG1_FCKM_DISABLE    0x00004000 /* Fail-safe clock monitor disable */
#define DEVCFG1_FCKS_DISABLE    0x00008000 /* Clock switching disable */
#define DEVCFG1_WDTPS_MASK      0x001f0000 /* Watchdog postscale */
#define DEVCFG1_WDTPS_1         0x00000000 /* 1:1 */
#define DEVCFG1_WDTPS_2         0x00010000 /* 1:2 */
#define DEVCFG1_WDTPS_4         0x00020000 /* 1:4 */
#define DEVCFG1_WDTPS_8         0x00030000 /* 1:8 */
#define DEVCFG1_WDTPS_16        0x00040000 /* 1:16 */
#define DEVCFG1_WDTPS_32        0x00050000 /* 1:32 */
#define DEVCFG1_WDTPS_64        0x00060000 /* 1:64 */
#define DEVCFG1_WDTPS_128       0x00070000 /* 1:128 */
#define DEVCFG1_WDTPS_256       0x00080000 /* 1:256 */
#define DEVCFG1_WDTPS_512       0x00090000 /* 1:512 */
#define DEVCFG1_WDTPS_1024      0x000a0000 /* 1:1024 */
#define DEVCFG1_WDTPS_2048      0x000b0000 /* 1:2048 */
#define DEVCFG1_WDTPS_4096      0x000c0000 /* 1:4096 */
#define DEVCFG1_WDTPS_8192      0x000d0000 /* 1:8192 */
#define DEVCFG1_WDTPS_16384     0x000e0000 /* 1:16384 */
#define DEVCFG1_WDTPS_32768     0x000f0000 /* 1:32768 */
#define DEVCFG1_WDTPS_65536     0x00100000 /* 1:65536 */
#define DEVCFG1_WDTPS_131072    0x00110000 /* 1:131072 */
#define DEVCFG1_WDTPS_262144    0x00120000 /* 1:262144 */
#define DEVCFG1_WDTPS_524288    0x00130000 /* 1:524288 */
#define DEVCFG1_WDTPS_1048576   0x00140000 /* 1:1048576 */
#define DEVCFG1_FWDTEN          0x00800000 /* Watchdog enable */

/*
 * Config2 register at 1fc02ff4.
 */
#define DEVCFG2_UNUSED          0xfff87888
#define DEVCFG2_FPLLIDIV_MASK   0x00000007 /* PLL input divider */
#define DEVCFG2_FPLLIDIV_1      0x00000000 /* 1x */
#define DEVCFG2_FPLLIDIV_2      0x00000001 /* 2x */
#define DEVCFG2_FPLLIDIV_3      0x00000002 /* 3x */
#define DEVCFG2_FPLLIDIV_4      0x00000003 /* 4x */
#define DEVCFG2_FPLLIDIV_5      0x00000004 /* 5x */
#define DEVCFG2_FPLLIDIV_6      0x00000005 /* 6x */
#define DEVCFG2_FPLLIDIV_10     0x00000006 /* 10x */
#define DEVCFG2_FPLLIDIV_12     0x00000007 /* 12x */
#define DEVCFG2_FPLLMUL_MASK    0x00000070 /* PLL multiplier */
#define DEVCFG2_FPLLMUL_15      0x00000000 /* 15x */
#define DEVCFG2_FPLLMUL_16      0x00000010 /* 16x */
#define DEVCFG2_FPLLMUL_17      0x00000020 /* 17x */
#define DEVCFG2_FPLLMUL_18      0x00000030 /* 18x */
#define DEVCFG2_FPLLMUL_19      0x00000040 /* 19x */
#define DEVCFG2_FPLLMUL_20      0x00000050 /* 20x */
#define DEVCFG2_FPLLMUL_21      0x00000060 /* 21x */
#define DEVCFG2_FPLLMUL_24      0x00000070 /* 24x */
#define DEVCFG2_UPLLIDIV_MASK   0x00000700 /* USB PLL input divider */
#define DEVCFG2_UPLLIDIV_1      0x00000000 /* 1x */
#define DEVCFG2_UPLLIDIV_2      0x00000100 /* 2x */
#define DEVCFG2_UPLLIDIV_3      0x00000200 /* 3x */
#define DEVCFG2_UPLLIDIV_4      0x00000300 /* 4x */
#define DEVCFG2_UPLLIDIV_5      0x00000400 /* 5x */
#define DEVCFG2_UPLLIDIV_6      0x00000500 /* 6x */
#define DEVCFG2_UPLLIDIV_10     0x00000600 /* 10x */
#define DEVCFG2_UPLLIDIV_12     0x00000700 /* 12x */
#define DEVCFG2_UPLLDIS         0x00008000 /* Disable USB PLL */
#define DEVCFG2_FPLLODIV_MASK   0x00070000 /* Default postscaler for PLL */
#define DEVCFG2_FPLLODIV_1      0x00000000 /* 1x */
#define DEVCFG2_FPLLODIV_2      0x00010000 /* 2x */
#define DEVCFG2_FPLLODIV_4      0x00020000 /* 4x */
#define DEVCFG2_FPLLODIV_8      0x00030000 /* 8x */
#define DEVCFG2_FPLLODIV_16     0x00040000 /* 16x */
#define DEVCFG2_FPLLODIV_32     0x00050000 /* 32x */
#define DEVCFG2_FPLLODIV_64     0x00060000 /* 64x */
#define DEVCFG2_FPLLODIV_256    0x00070000 /* 256x */

/*
 * Config3 register at 1fc02ff0.
 */
#define DEVCFG3_UNUSED          0x38f80000
#define DEVCFG3_USERID_MASK     0x0000ffff /* User-defined ID */
#define DEVCFG3_USERID(x)       ((x) & 0xffff)
#define DEVCFG3_FSRSSEL_MASK    0x00070000 /* SRS select */
#define DEVCFG3_FSRSSEL_ALL     0x00000000 /* All irqs assigned to shadow set */
#define DEVCFG3_FSRSSEL_1       0x00010000 /* Assign irq priority 1 to shadow set */
#define DEVCFG3_FSRSSEL_2       0x00020000 /* Assign irq priority 2 to shadow set */
#define DEVCFG3_FSRSSEL_3       0x00030000 /* Assign irq priority 3 to shadow set */
#define DEVCFG3_FSRSSEL_4       0x00040000 /* Assign irq priority 4 to shadow set */
#define DEVCFG3_FSRSSEL_5       0x00050000 /* Assign irq priority 5 to shadow set */
#define DEVCFG3_FSRSSEL_6       0x00060000 /* Assign irq priority 6 to shadow set */
#define DEVCFG3_FSRSSEL_7       0x00070000 /* Assign irq priority 7 to shadow set */
#define DEVCFG3_FMIIEN          0x01000000 /* Ethernet MII enable */
#define DEVCFG3_FETHIO          0x02000000 /* Ethernet pins default */
#define DEVCFG3_FCANIO          0x04000000 /* CAN pins default */
#define DEVCFG3_FUSBIDIO        0x40000000 /* USBID pin: controlled by USB */
#define DEVCFG3_FVBUSONIO       0x80000000 /* VBuson pin: controlled by USB */

/*
 * Interrupt Control register.
 */
#define PIC32_INTCON_INT0EP	0x0001	/* External interrupt 0 polarity rising edge */
#define PIC32_INTCON_INT1EP	0x0002	/* External interrupt 1 polarity rising edge */
#define PIC32_INTCON_INT2EP	0x0004	/* External interrupt 2 polarity rising edge */
#define PIC32_INTCON_INT3EP	0x0008	/* External interrupt 3 polarity rising edge */
#define PIC32_INTCON_INT4EP	0x0010	/* External interrupt 4 polarity rising edge */
#define PIC32_INTCON_TPC(x)	((x)<<8) /* Temporal proximity group priority */
#define PIC32_INTCON_MVEC	0x1000	/* Multi-vectored mode */
#define PIC32_INTCON_FRZ	0x4000	/* Freeze in debug mode */
#define PIC32_INTCON_SS0	0x8000	/* Single vector has a shadow register set */

/*
 * Interrupt Status register.
 */
#define PIC32_INTSTAT_VEC(s)	((s) & 0xFF)	/* Interrupt vector */
#define PIC32_INTSTAT_SRIPL(s)	((s) >> 8 & 7)	/* Requested priority level */
#define PIC32_INTSTAT_SRIPL_MASK 0x0700

/*
 * Interrupt Prority Control register.
 */
#define PIC32_IPC_IS0(x)	(x)		/* Interrupt 0 subpriority */
#define PIC32_IPC_IP0(x)	((x)<<2)	/* Interrupt 0 priority */
#define PIC32_IPC_IS1(x)	((x)<<8)	/* Interrupt 1 subpriority */
#define PIC32_IPC_IP1(x)	((x)<<10)	/* Interrupt 1 priority */
#define PIC32_IPC_IS2(x)	((x)<<16)	/* Interrupt 2 subpriority */
#define PIC32_IPC_IP2(x)	((x)<<18)	/* Interrupt 2 priority */
#define PIC32_IPC_IS3(x)	((x)<<24)	/* Interrupt 3 subpriority */
#define PIC32_IPC_IP3(x)	((x)<<26)	/* Interrupt 3 priority */

/*
 * IRQ numbers for PIC32MX3xx/4xx/5xx/6xx/7xx
 */
#define PIC32_IRQ_CT        0   /* Core Timer Interrupt */
#define PIC32_IRQ_CS0       1   /* Core Software Interrupt 0 */
#define PIC32_IRQ_CS1       2   /* Core Software Interrupt 1 */
#define PIC32_IRQ_INT0      3   /* External Interrupt 0 */
#define PIC32_IRQ_T1        4   /* Timer1 */
#define PIC32_IRQ_IC1       5   /* Input Capture 1 */
#define PIC32_IRQ_OC1       6   /* Output Compare 1 */
#define PIC32_IRQ_INT1      7   /* External Interrupt 1 */
#define PIC32_IRQ_T2        8   /* Timer2 */
#define PIC32_IRQ_IC2       9   /* Input Capture 2 */
#define PIC32_IRQ_OC2       10  /* Output Compare 2 */
#define PIC32_IRQ_INT2      11  /* External Interrupt 2 */
#define PIC32_IRQ_T3        12  /* Timer3 */
#define PIC32_IRQ_IC3       13  /* Input Capture 3 */
#define PIC32_IRQ_OC3       14  /* Output Compare 3 */
#define PIC32_IRQ_INT3      15  /* External Interrupt 3 */
#define PIC32_IRQ_T4        16  /* Timer4 */
#define PIC32_IRQ_IC4       17  /* Input Capture 4 */
#define PIC32_IRQ_OC4       18  /* Output Compare 4 */
#define PIC32_IRQ_INT4      19  /* External Interrupt 4 */
#define PIC32_IRQ_T5        20  /* Timer5 */
#define PIC32_IRQ_IC5       21  /* Input Capture 5 */
#define PIC32_IRQ_OC5       22  /* Output Compare 5 */
#define PIC32_IRQ_SPI1E     23  /* SPI1 Fault */
#define PIC32_IRQ_SPI1TX    24  /* SPI1 Transfer Done */
#define PIC32_IRQ_SPI1RX    25  /* SPI1 Receive Done */

#define PIC32_IRQ_SPI3E     26  /* SPI3 Fault */
#define PIC32_IRQ_SPI3TX    27  /* SPI3 Transfer Done */
#define PIC32_IRQ_SPI3RX    28  /* SPI3 Receive Done */
#define PIC32_IRQ_U1E       26  /* UART1 Error */
#define PIC32_IRQ_U1RX      27  /* UART1 Receiver */
#define PIC32_IRQ_U1TX      28  /* UART1 Transmitter */
#define PIC32_IRQ_I2C3B     26  /* I2C3 Bus Collision Event */
#define PIC32_IRQ_I2C3S     27  /* I2C3 Slave Event */
#define PIC32_IRQ_I2C3M     28  /* I2C3 Master Event */

#define PIC32_IRQ_I2C1B     29  /* I2C1 Bus Collision Event */
#define PIC32_IRQ_I2C1S     30  /* I2C1 Slave Event */
#define PIC32_IRQ_I2C1M     31  /* I2C1 Master Event */
#define PIC32_IRQ_CN        32  /* Input Change Interrupt */
#define PIC32_IRQ_AD1       33  /* ADC1 Convert Done */
#define PIC32_IRQ_PMP       34  /* Parallel Master Port */
#define PIC32_IRQ_CMP1      35  /* Comparator Interrupt */
#define PIC32_IRQ_CMP2      36  /* Comparator Interrupt */

#define PIC32_IRQ_SPI2E     37  /* SPI2 Fault */
#define PIC32_IRQ_SPI2TX    38  /* SPI2 Transfer Done */
#define PIC32_IRQ_SPI2RX    39  /* SPI2 Receive Done */
#define PIC32_IRQ_U3E       37  /* UART3 Error */
#define PIC32_IRQ_U3RX      38  /* UART3 Receiver */
#define PIC32_IRQ_U3TX      39  /* UART3 Transmitter */
#define PIC32_IRQ_I2C4B     37  /* I2C4 Bus Collision Event */
#define PIC32_IRQ_I2C4S     38  /* I2C4 Slave Event */
#define PIC32_IRQ_I2C4M     39  /* I2C4 Master Event */

#define PIC32_IRQ_SPI4E     40  /* SPI4 Fault */
#define PIC32_IRQ_SPI4TX    41  /* SPI4 Transfer Done */
#define PIC32_IRQ_SPI4RX    42  /* SPI4 Receive Done */
#define PIC32_IRQ_U2E       40  /* UART2 Error */
#define PIC32_IRQ_U2RX      41  /* UART2 Receiver */
#define PIC32_IRQ_U2TX      42  /* UART2 Transmitter */
#define PIC32_IRQ_I2C5B     40  /* I2C5 Bus Collision Event */
#define PIC32_IRQ_I2C5S     41  /* I2C5 Slave Event */
#define PIC32_IRQ_I2C5M     42  /* I2C5 Master Event */

#define PIC32_IRQ_I2C2B     43  /* I2C2 Bus Collision Event */
#define PIC32_IRQ_I2C2S     44  /* I2C2 Slave Event */
#define PIC32_IRQ_I2C2M     45  /* I2C2 Master Event */
#define PIC32_IRQ_FSCM      46  /* Fail-Safe Clock Monitor */
#define PIC32_IRQ_RTCC      47  /* Real-Time Clock and Calendar */
#define PIC32_IRQ_DMA0      48  /* DMA Channel 0 */
#define PIC32_IRQ_DMA1      49  /* DMA Channel 1 */
#define PIC32_IRQ_DMA2      50  /* DMA Channel 2 */
#define PIC32_IRQ_DMA3      51  /* DMA Channel 3 */
#define PIC32_IRQ_DMA4      52  /* DMA Channel 4 */
#define PIC32_IRQ_DMA5      53  /* DMA Channel 5 */
#define PIC32_IRQ_DMA6      54  /* DMA Channel 6 */
#define PIC32_IRQ_DMA7      55  /* DMA Channel 7 */
#define PIC32_IRQ_FCE       56  /* Flash Control Event */
#define PIC32_IRQ_USB       57  /* USB */
#define PIC32_IRQ_CAN1      58  /* Control Area Network 1 */
#define PIC32_IRQ_CAN2      59  /* Control Area Network 2 */
#define PIC32_IRQ_ETH       60  /* Ethernet Interrupt */
#define PIC32_IRQ_IC1E      61  /* Input Capture 1 Error */
#define PIC32_IRQ_IC2E      62  /* Input Capture 2 Error */
#define PIC32_IRQ_IC3E      63  /* Input Capture 3 Error */
#define PIC32_IRQ_IC4E      64  /* Input Capture 4 Error */
#define PIC32_IRQ_IC5E      65  /* Input Capture 5 Error */
#define PIC32_IRQ_PMPE      66  /* Parallel Master Port Error */
#define PIC32_IRQ_U4E       67  /* UART4 Error */
#define PIC32_IRQ_U4RX      68  /* UART4 Receiver */
#define PIC32_IRQ_U4TX      69  /* UART4 Transmitter */
#define PIC32_IRQ_U6E       70  /* UART6 Error */
#define PIC32_IRQ_U6RX      71  /* UART6 Receiver */
#define PIC32_IRQ_U6TX      72  /* UART6 Transmitter */
#define PIC32_IRQ_U5E       73  /* UART5 Error */
#define PIC32_IRQ_U5RX      74  /* UART5 Receiver */
#define PIC32_IRQ_U5TX      75  /* UART5 Transmitter */

/*
 * Interrupt vector numbers for PIC32MX3xx/4xx/5xx/6xx/7xx
 */
#define PIC32_VECT_CT       0   /* Core Timer Interrupt */
#define PIC32_VECT_CS0      1   /* Core Software Interrupt 0 */
#define PIC32_VECT_CS1      2   /* Core Software Interrupt 1 */
#define PIC32_VECT_INT0     3   /* External Interrupt 0 */
#define PIC32_VECT_T1       4   /* Timer1 */
#define PIC32_VECT_IC1      5   /* Input Capture 1 */
#define PIC32_VECT_OC1      6   /* Output Compare 1 */
#define PIC32_VECT_INT1     7   /* External Interrupt 1 */
#define PIC32_VECT_T2       8   /* Timer2 */
#define PIC32_VECT_IC2      9   /* Input Capture 2 */
#define PIC32_VECT_OC2      10  /* Output Compare 2 */
#define PIC32_VECT_INT2     11  /* External Interrupt 2 */
#define PIC32_VECT_T3       12  /* Timer3 */
#define PIC32_VECT_IC3      13  /* Input Capture 3 */
#define PIC32_VECT_OC3      14  /* Output Compare 3 */
#define PIC32_VECT_INT3     15  /* External Interrupt 3 */
#define PIC32_VECT_T4       16  /* Timer4 */
#define PIC32_VECT_IC4      17  /* Input Capture 4 */
#define PIC32_VECT_OC4      18  /* Output Compare 4 */
#define PIC32_VECT_INT4     19  /* External Interrupt 4 */
#define PIC32_VECT_T5       20  /* Timer5 */
#define PIC32_VECT_IC5      21  /* Input Capture 5 */
#define PIC32_VECT_OC5      22  /* Output Compare 5 */
#define PIC32_VECT_SPI1     23  /* SPI1 */

#define PIC32_VECT_SPI3     24  /* SPI3 */
#define PIC32_VECT_U1       24  /* UART1 */
#define PIC32_VECT_I2C3     24  /* I2C3 */

#define PIC32_VECT_I2C1     25  /* I2C1 */
#define PIC32_VECT_CN       26  /* Input Change Interrupt */
#define PIC32_VECT_AD1      27  /* ADC1 Convert Done */
#define PIC32_VECT_PMP      28  /* Parallel Master Port */
#define PIC32_VECT_CMP1     29  /* Comparator Interrupt */
#define PIC32_VECT_CMP2     30  /* Comparator Interrupt */

#define PIC32_VECT_SPI2     31  /* SPI2 */
#define PIC32_VECT_U3       31  /* UART3 */
#define PIC32_VECT_I2C4     31  /* I2C4 */

#define PIC32_VECT_SPI4     32  /* SPI4 */
#define PIC32_VECT_U2       32  /* UART2 */
#define PIC32_VECT_I2C5     32  /* I2C5 */

#define PIC32_VECT_I2C2     33  /* I2C2 */
#define PIC32_VECT_FSCM     34  /* Fail-Safe Clock Monitor */
#define PIC32_VECT_RTCC     35  /* Real-Time Clock and Calendar */
#define PIC32_VECT_DMA0     36  /* DMA Channel 0 */
#define PIC32_VECT_DMA1     37  /* DMA Channel 1 */
#define PIC32_VECT_DMA2     38  /* DMA Channel 2 */
#define PIC32_VECT_DMA3     39  /* DMA Channel 3 */
#define PIC32_VECT_DMA4     40  /* DMA Channel 4 */
#define PIC32_VECT_DMA5     41  /* DMA Channel 5 */
#define PIC32_VECT_DMA6     42  /* DMA Channel 6 */
#define PIC32_VECT_DMA7     43  /* DMA Channel 7 */
#define PIC32_VECT_FCE      44  /* Flash Control Event */
#define PIC32_VECT_USB      45  /* USB */
#define PIC32_VECT_CAN1     46  /* Control Area Network 1 */
#define PIC32_VECT_CAN2     47  /* Control Area Network 2 */
#define PIC32_VECT_ETH      48  /* Ethernet Interrupt */
#define PIC32_VECT_U4       49  /* UART4 */
#define PIC32_VECT_U6       50  /* UART6 */
#define PIC32_VECT_U5       51  /* UART5 */

#endif /* _IO_PIC32MX_H */
