import React,{Component} from 'react';
import styled from 'styled-components';

export default class TaskListItem extends Component{
    constructor(props){
        super(props);
        this.state = {
            name: props.titulo,
            status:props.state,
            idtask: props.id,
            colors: props.colors,
        }
        this.setStatusItem = this.setStatusItem.bind(this);
        this.openModal = this.openModal.bind(this);
    }
    setStatusItem(idt){
        this.setState({
            status:idt.target.value,
        });
        console.log('Cambia estado item ',idt.target.value)
    }
    openModal(){
        console.log('open modal',this.state.idtask)
        this.props.onClick(this.state.idtask);
    }
    render(){
        return(
            <Item key={this.state.idtask} color={this.state.colors[this.state.status]}>
            <ULtag>
                <LItagLavel key="0">Change Status: </LItagLavel>
                <Select id="great-names" onChange={this.setStatusItem}>
                {
                    this.props.nombres.map((name,i)=>{
                        return this.props.state===i?<option value={i} key={i} selected>{name}</option>:<option value={i} key={i}>{name}</option>
                    })
                }
                </Select>
            </ULtag>
            <Title onClick={this.openModal}>{this.state.name}</Title>
            <Parrafo color={this.state.colors[this.state.status]}>Description task!</Parrafo>
        </Item>
        )
    }
}


const Item = styled.li.attrs({
    'border-color': props => props.color,
})`
    display: inline-block;
    margin: 10px 2% 25px;
    background: rgba(0,0,0,.3);
    padding: 10px 10px 20px 20px;
    width: 21%;
    border-radius: 7px;
    border: 3px solid;
    border-color: ${props=>props.color};
`;

const Title = styled.a`
    margin:0;
    color:#fff!important;
    font-size:18px;
    cursor:pointer;
`;
const Parrafo = styled.p.attrs({
    color: props => props.color,
})`
    font-size:12px;
    color: ${props=>props.color};
`;
const Select = styled.select`
    font-size:11px;
`

const ULtag = styled.div`
    margin-bottom:15px;
    text-align:right;
    vertical-align:top;
    position:relative;
`;
const LItag = styled.div`
    display: inline-block;
`;
const LItagLavel = LItag.extend`
    color: #fff;
    right: 95px;
    font-size: 10px;
    position: absolute;
    width: 80px;
    top: 6px;
`;