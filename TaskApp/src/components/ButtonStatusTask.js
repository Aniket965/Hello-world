import React from 'React';
import styled from 'styled-components';

const ButtonStatusTask = ({handleClick, color, texto, idStatus}) => (
    <Btn onClick={() => handleClick(idStatus)}>
        <Icon color={color}/>
        <Text>{texto}</Text>
    </Btn>
);

export default ButtonStatusTask;

const Btn = styled.a`
    display: block;
    width: 80%;
    margin: 15px 10%;
    text-align:left;
    cursor: pointer;
    padding: 8px;
    transition: all 0.5s ease;
    &:hover{
        background:rgba(255,255,255,.2);
    }
`;
const Icon = styled.div.attrs({
    background: props => props.color || '#ffc107'
})`
    display: inline-block;
    height:20px;
    width:20px;
    border-radius: 50%;
    background: ${props => props.color};
    box-shadow: 0px 0px 20px ${props => props.color};
`;

const Text = styled.div`
    color: #fff;
    display:inline-block;
    position: absolute;
    margin-left: 15px;
    line-height: 20px;
`;