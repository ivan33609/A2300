/** Name: ConfigRf.h
*
* Copyright(c) 2013 Loctronix Corporation
* http://www.loctronix.com
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/

#ifndef CONFIGRF_H_
#define CONFIGRF_H_

#include <A2300/A2300_Defs.h>
#include <string>

namespace A2300
{
class ConfigDevice;

class ConfigRf : public IConfigComponent
{
public:
	ConfigRf(int idComponent, const std::string& sname, ConfigDevice* pDevice );
	virtual ~ConfigRf();

	/* Define IConfigComponent interface*/
	virtual std::string name();
	virtual int  componentId();
	virtual void Reset();
	virtual void Synch();

	uint32	RxFrequency( uint32 freqKhz);
	uint32  RxFrequency() const;
	byte	RxGain( byte gainDb);
	byte    RxGain() const;
	byte	RxPath( byte idPath);
	byte    RxPath() const;
	RfBandwidthValuesEnum RxBandwidth( RfBandwidthValuesEnum bw);
	RfBandwidthValuesEnum RxBandwidth( ) const;

	uint32 TxFrequency( uint32 freqkHz);
	uint32 TxFrequency( ) const;
	byte TxGain( byte gainDb);
	byte TxGain( ) const;
	byte TxPath( byte idPath);
	byte TxPath( ) const;
	RfBandwidthValuesEnum TxBandwidth( RfBandwidthValuesEnum bw);
	RfBandwidthValuesEnum TxBandwidth( ) const;

private:
	int  m_idComponent;
	std::string m_sName;
	uint32  m_rxfreq;
	byte    m_rxgain;
	byte    m_rxpath;		
	RfBandwidthValuesEnum m_rxbw;

	uint32  m_txfreq;
	byte    m_txgain;
	byte    m_txpath;		
	RfBandwidthValuesEnum m_txbw;

	ConfigDevice* m_pDevice;
};

} /* namespace A2300 */
#endif /* CONFIGRF_H_ */
