#ifndef __COLOR_H
#define __COLOR_H

#include <math.h>

class CRTColor
{
	public :

		CRTColor ()
			:	m_fR	(0.0f),
				m_fG	(0.0f),
				m_fB	(0.0f)
		{
		}

		CRTColor (float fR,float fG,float fB)
			:	m_fR	(fR),
				m_fG	(fG),
				m_fB	(fB)
		{
		}
		
		CRTColor (float fValue)
			:	m_fR	(fValue),
				m_fG	(fValue),
				m_fB	(fValue)
		{
		}

		bool IsBlack () const { return ( (m_fR==0.0f) && (m_fG==0.0f) && (m_fB==0.0f) ) ; }

		bool IsWhite () const { return ( (m_fR==1.0f) && (m_fG==1.0f) && (m_fB==1.0f) ) ; }

		CRTColor operator + (const CRTColor & c) const
		{
			return CRTColor (m_fR+c.m_fR,m_fG+c.m_fG,m_fB+c.m_fB) ;
		}

		CRTColor operator - (const CRTColor & c) const
		{
			return CRTColor (m_fR-c.m_fR,m_fG-c.m_fG,m_fB-c.m_fB) ;
		}

		CRTColor operator * (float fFactor) const
		{
			return CRTColor (m_fR*fFactor,m_fG*fFactor,m_fB*fFactor) ;
		}

		CRTColor operator * (const CRTColor & cColor) const
		{
			return CRTColor (m_fR*cColor.m_fR,m_fG*cColor.m_fG,m_fB*cColor.m_fB) ;
		}

		CRTColor operator / (float fFactor) const
		{
			return CRTColor (m_fR/fFactor,m_fG/fFactor,m_fB/fFactor) ;
		}

		CRTColor operator ^ (float k)           const
		{
			return CRTColor ((float)pow(m_fR,k),(float)pow(m_fG,k),(float)pow(m_fB,k)) ;
		}
		
		CRTColor & operator += (const CRTColor & cColor)
		{
			m_fR+=cColor.m_fR;
			m_fG+=cColor.m_fG;
			m_fB+=cColor.m_fB;
			return *this;
		}

		CRTColor & operator -= (const CRTColor & cColor)
		{
			m_fR-=cColor.m_fR;
			m_fG-=cColor.m_fG;
			m_fB-=cColor.m_fB;
			return *this;
		}

		CRTColor & operator *= (float fFactor)
		{
			m_fR*=fFactor;
			m_fG*=fFactor;
			m_fB*=fFactor;
			return *this;
		}

		CRTColor & operator *= (const CRTColor & cColor)
		{
			m_fR*=cColor.m_fR;
			m_fG*=cColor.m_fG;
			m_fB*=cColor.m_fB;
			return *this;
		}

		CRTColor & operator /= (float fFactor)
		{
			m_fR/=fFactor;
			m_fG/=fFactor;
			m_fB/=fFactor;
			return *this;
		}

		bool operator == ( const CRTColor &cColor ) const
		{
			return ( (m_fR==cColor.m_fR) && (m_fG==cColor.m_fG) && (m_fB==cColor.m_fB) ) ;
		}

		bool operator != ( const CRTColor &cColor ) const
		{
			return ( (m_fR!=cColor.m_fR) || (m_fG!=cColor.m_fG) || (m_fB!=cColor.m_fB) ) ;
		}

		float m_fR , m_fG , m_fB ;
} ;

#endif
