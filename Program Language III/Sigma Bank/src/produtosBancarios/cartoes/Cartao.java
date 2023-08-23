package produtosBancarios.cartoes;

import utils.Data;
import utils.Gerais;

public abstract class Cartao implements Gerais {

    // Atributos da Classe
    private Data vencimento;
    private Data validade;
    private double limite;
    private final double anuidade = 0d;
    private double fatura;
    private long numCartao;
    private int senha;

    // Construtor com 3 parâmetros
    public Cartao( int dia, double limite, int senha ) {

        if( validaCartao( dia, limite) ) {
            this.vencimento = new Data( dia, 1 );
            this.limite = limite;
        } else {
            this.vencimento = new Data(1, 1);
            this.limite = 0.0d;
        }

        this.senha = senha;
        this.validade = new Data( 2025 );
    }

    // Construtor com 2 parâmetros
    public Cartao( double limite, int senha ) {
        this( 1, limite, senha );
    }

    // Método para verificar se os dados são válidos
    private boolean validaCartao( int dia, double limite ) {
        return dia >= 1 && dia <= 31 && limite >= 0;
    }

    // Sobreescrita do método pagar, previsto na Interface
    @Override
    public boolean pagar( double pagamento ) {

        if( this.fatura >= pagamento ) {
            this.fatura -= pagamento;
            this.limite += pagamento;
            return true;
        }

        return false;

    }

    // Método para compra com o Cartão
    public boolean comprarAlgo( double valor, int senha ) {

        if( this.limite >= valor && this.senha == senha) {
            this.limite -= valor;
            this.fatura += valor;
            return true;
        }

        return false;
    }

    // Sobreescrita do método getSaldo, previsto na Interface
    @Override
    public double getSaldo() {
        return this.limite;
    }

    // Sobreescrita do método toString, previsto na Interface
    @Override
    public String toString() {
        return "Limite: " + this.limite + "Num. Cartão: " + this.numCartao + "Validade: " + this.validade;
    }

    // Menu para o cartão
    public static void menuCartao() {

        System.out.println( "1 - Novo Cartão" );
        System.out.println( "2 - Consultar cartão" );
        System.out.println( "3 - Comprar algo" );
        System.out.println( "4 - Pagar cartão" );
        System.out.println( "5 - Voltar" );

    }

    // Método de verificação para Cartão
    public static boolean isCartao( Cartao cartao ) {
        return cartao != null;
    }

}