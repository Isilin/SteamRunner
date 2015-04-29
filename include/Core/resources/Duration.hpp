#ifndef DURATION_HPP_INCLUDED
#define DURATION_HPP_INCLUDED

class Duration{
public :
    Duration(const int remainingTurnsIn, bool temporaryIn = false) ;
    Duration(const Duration& cloneIn) ;
    virtual ~Duration() ;
    Duration& operator--() ;

    bool IsTemporary() const ;
    bool IsFinished() const ;
protected :
    int RemainingTurns() const ;
private :
    int _remainingTurns ;
    bool _temporary ;
} ;

#endif // DURATION_HPP_INCLUDED
