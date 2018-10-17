import React, {Component} from 'react';
import styled from 'styled-components';

export default class TaskDetail extends Component{
    constructor(props){
        super(props);
        this.state = {
            visible:props.visible
        }
    }
    render(){
        console.log('Modal',this.props.colores[this.props.detalle.taskstatus])
        return (
            <Modal visible={this.props.visible}>
                <Detail color={this.props.colores[this.props.detalle.taskstatus]}>
                    <TitleTask color={this.props.colores[this.props.detalle.taskstatus]}>{this.props.detalle.taskTitulo}</TitleTask>
                    <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Veniam tempore fuga quas dolore ut saepe cupiditate deserunt quo recusandae harum ab, error facere hic sint mollitia obcaecati sit blanditiis reprehenderit. Animi illum exercitationem dolores aut! Veniam vel nulla totam, quidem mollitia temporibus expedita natus magni.</p>
                    <Cerrar onClick={this.props.onClick}>Cerrar</Cerrar>
                </Detail>
            </Modal>
        );
    }
}

const Modal = styled.div.attrs({
    display: props => props.visible=='on' ? 'block' : 'none',
})`
    display: ${props => props.visible=='on' ? 'block' : 'none'};
    position: absolute;
    width: 100%;
    height: 100%;
    background: rgba(18, 8, 39, 0.85);
    top: 0;
`
const Detail = styled.div.attrs({
    'border-color': props => props.color,
})`
    position: relative;
    width: 500px;
    height: auto;
    background: rgba(0,0,0,.8);
    color: #fff;
    margin: 0 auto;
    top: 30%;
    padding: 15px 50px 30px;
    border-radius: 7px;
    border: 3px solid;
    border-color: ${props=>props.color};
`
const TitleTask = styled.h2.attrs({
    color: props => props.color
})`
    color: ${props => props.color};
    margin: 25px 35px 25px 0;
    display: inline-block;
`;
const Cerrar = styled.a`
    position: absolute;
    top: -32px;
    right: 0;
    color: #fff !important;
    cursor: pointer;
`