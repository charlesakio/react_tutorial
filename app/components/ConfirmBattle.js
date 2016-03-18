var React = require('react');
//var PropTypes = require('react.propTypes')

function ConfirmBattle (props) {
  return props.isLoading == true
    ? <p>LOADING </p>
    : <p> CONFIRM BATTLE </p>
}

/*
ConfirmBattle.propTypes = {
  isLoading: PropTypes.bool.isRequired,
  playerInfo: PropTypes.array.isRequired
}
*/
module.exports = ConfirmBattle;
