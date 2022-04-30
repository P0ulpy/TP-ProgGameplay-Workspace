//
// Created by Flo on 15/04/2022.
//

#ifdef INCLUDE_TP6

#ifndef TP_PROGGAMEPLAY_WORKSPACE_NOT_FINISHED_HPP
#define TP_PROGGAMEPLAY_WORKSPACE_NOT_FINISHED_HPP

template<typename StateType>
class MomentoT
{
public:
    explicit MomentoT(const StateType& state);

    StateType getSaved() const;

private:
    StateType m_state;
};

template<typename StateType>
MomentoT<StateType>::MomentoT(const StateType &state) {

}

template<typename StateType>
StateType MomentoT<StateType>::getSaved() const {
    return m_state;
}

template<typename DerivatedType, typename StateType>
class Originator
{
public:
    using state_type = StateType;
    // crtp : Curious Repeated Template Pattern
    using crtp = Originator;

    virtual ~Originator() = default;
    MomentoT<StateType>* save()
    {
        auto& derived = static_cast<DerivatedType>(*this);
        derived->_save();
        return new MomentoT<StateType>(m_state);
    }

    void restore(const MomentoT<StateType>& memento)
    {
        m_state = memento.getSaved();
        auto& derived = static_cast<DerivatedType&>(*this);
        derived._restore();
    }

protected:

    void _save() {}
    void _restore() {}

    StateType m_state;
};

#include <vector>

template<typename Originator>
class Caretaker
{
public:
    explicit Caretaker(std::shared_ptr<Originator> pOriginator);

    void createMomentot()
    {
        //m_backups.push_back()
    }
private:
    std::vector<Memento<typename Originator::state_type>*> m_backups;
    std::shared_ptr<Originator> m_pOriginator;
};

#endif //TP_PROGGAMEPLAY_WORKSPACE_NOT_FINISHED_HPP

#endif // INCLUDE_TP6
